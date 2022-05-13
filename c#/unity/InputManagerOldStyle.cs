using System.Collections;
using System.Collections.Generic;
using UnityEngine;

enum FingerNumbers
{
    NoFinger,
    OneFinger,
    TwoFingers,
    ThreeFingers,
    WrongState
}

enum TouchState
{
    Idle,
    MaybeTap,
    Move,
    Zoom,
    Rotate,
    Scroll,
}

public class InputManagerOldStyle : MonoBehaviour
{
    FingerNumbers fingerNumbers = FingerNumbers.NoFinger;
    TouchState oneTouch = TouchState.Idle;
    TouchState twoTouch = TouchState.Idle;
    TouchState threeTouch = TouchState.Idle;
    bool mouseDragging = false;
    bool maybeClick = false;
    Vector2 startTouchPos;
    Vector2 startScreenTouchPos, startTwoFingerPos;
    Vector2 startDragingPos ;
    Vector2 startClipPos ;
    float startTwoFingerDist, startTwoFingerAngle;
    TaiwanMap taiwanMap;
    Terrain terrain;
    RabbitMQClient messageBroker;
    TroopManager troopManager;
    public float disableInputFrom;
    public bool mapUpdating = true;

    Camera twTerrainCam;
    Ray ray;
    RaycastHit hit;

    void Awake()
    {
        taiwanMap = FindObjectOfType<TaiwanMap>();
        terrain = FindObjectOfType<Terrain>();
        messageBroker = FindObjectOfType<RabbitMQClient>();
        troopManager = FindObjectOfType<TroopManager>();
        twTerrainCam = FindObjectOfType<Camera>();
    }

    void ParseOneFingerEvent()
    {
        Touch touch = Input.GetTouch(0);
        switch (oneTouch)
        {
            case TouchState.Idle:
                if (touch.phase == TouchPhase.Began)
                {
                    startTouchPos = new Vector2(taiwanMap.newPos.x, taiwanMap.newPos.y);
                    startScreenTouchPos = touch.position;
                    oneTouch = TouchState.MaybeTap;
                }
                break;

            case TouchState.MaybeTap:
                if (touch.phase == TouchPhase.Ended)
                {
                    // taiwanMap.SetWiregridEnable(!taiwanMap.useWireterrain);
                    
                    // Ray ray = Camera.main.ScreenPointToRay(touch.position);
                    // RaycastHit hit;
                    // if (Physics.Raycast(ray, out hit))  // 如果ray觸及任何Collider
                    // {
                    //     taiwanMap.PutSoldier(hit.point);
                    // }
                }
                else if (touch.phase == TouchPhase.Moved)
                {
                    Vector2 diff = touch.position - startScreenTouchPos;
                    if (diff.magnitude > 20)
                        oneTouch = TouchState.Move;
                }
                break;

            case TouchState.Move:
                if (touch.phase == TouchPhase.Moved)
                {
                    Vector2 diffScreen = touch.position - startScreenTouchPos;
                    Vector2 diffRelative = new Vector2(diffScreen.x / Screen.width, diffScreen.y / Screen.height);
                    Vector2 diff = startTouchPos - diffRelative * taiwanMap.terrainSize * taiwanMap.rangeScale;
                    taiwanMap.newPos = ((int) diff.x, (int) diff.y);
                }
                break;
        }
    }

    float CalculateAngle(Vector2 v1, Vector2 v2)
    {
        Vector2 diff = v1 - v2;
        float dist = Vector2.Distance(v1, v2);
        if (diff.x == 0)
        {
            if (diff.y > 0)
                return 90;
            else
                return 270;
        }
        float atan = Mathf.Atan(diff.y / diff.x);
        float acos = Mathf.Acos(diff.x / dist);
        if (acos > Mathf.PI)
            atan += Mathf.PI / 2;
        if (atan < 0)
            atan += Mathf.PI;
        return atan / Mathf.PI * 180;
    }

    void ParseTwoFingerEvent()
    {
        Touch touch0 = Input.GetTouch(0);
        Touch touch1 = Input.GetTouch(1);
        float dist = Vector2.Distance(touch0.position, touch1.position);
        Vector2 center = (touch0.position + touch1.position) / 2;
        float angle = CalculateAngle(touch0.position, touch1.position);
        Debug.Log($"dist={dist}, angle={angle}, center={center}");

        switch (twoTouch)
        {
            case TouchState.Idle:
                if (touch0.phase == TouchPhase.Moved && touch1.phase == TouchPhase.Moved)
                {
                    startTwoFingerDist = dist;
                    startTwoFingerPos = center;
                    startTwoFingerAngle = angle;
                    twoTouch = TouchState.Move;
                    Debug.Log($"Start {twoTouch}");
                }
                break;

            case TouchState.Move:
                if (touch0.phase == TouchPhase.Moved && touch1.phase == TouchPhase.Moved)
                {
                    if ((dist < startTwoFingerDist * 0.90) || (dist > startTwoFingerDist * 1.1))
                    {
                        twoTouch = TouchState.Zoom;
                        Debug.Log($"Start {twoTouch}");
                    }
                    else if (Vector2.Distance(center, startTwoFingerPos) > 20 &&
                        Mathf.Abs((CalculateAngle(center, startTwoFingerPos) % 180) - 90) < 5)
                    {
                        twoTouch = TouchState.Scroll;
                        Debug.Log($"Start {twoTouch}");
                    }
                }
                else
                {
                    twoTouch = TouchState.Idle;
                }
                break;

            case TouchState.Zoom:
                if (touch0.phase == TouchPhase.Moved && touch1.phase == TouchPhase.Moved)
                {
                    float scale = taiwanMap.rangeScale + (startTwoFingerDist / dist - 1);
                    taiwanMap.rangeScale = Mathf.Clamp(scale, 0.5f, 1.5f);
                }
                else
                {
                    twoTouch = TouchState.Idle;
                }
                break;

            case TouchState.Scroll:
                if (touch0.phase == TouchPhase.Moved && touch1.phase == TouchPhase.Moved)
                {
                    float scrollDistance = Vector2.Distance(center, startTwoFingerPos);
                    float sign = Mathf.Sign(center.y - startTwoFingerPos.y);
                    float scale = taiwanMap.rangeScale + sign * scrollDistance / 400;
                    taiwanMap.rangeScale = Mathf.Clamp(scale, 0.5f, 1.5f);
                }
                else
                {
                    twoTouch = TouchState.Idle;
                }
                break;
        }
    }

    void ParseThreeFingerEvent()
    {

    }

    void ProcessFingers()
    {
        int n = Input.touchCount;
        switch (fingerNumbers)
        {
            case FingerNumbers.NoFinger:
                if (n == 1) {
                    fingerNumbers = FingerNumbers.OneFinger;
                    oneTouch = TouchState.Idle;
                    ParseOneFingerEvent();
                }
                else if (n == 2) {
                    fingerNumbers = FingerNumbers.TwoFingers;
                    twoTouch = TouchState.Idle;
                    ParseTwoFingerEvent();
                }
                else if (n == 3) {
                    fingerNumbers = FingerNumbers.ThreeFingers;
                    threeTouch = TouchState.Idle;
                    ParseThreeFingerEvent();
                }
                else if (n >= 4) {
                    fingerNumbers = FingerNumbers.WrongState;
                }
                break;

            case FingerNumbers.OneFinger:
                if (n == 1) {
                    ParseOneFingerEvent();
                }
                else if (n == 0 || n == 2) {
                    fingerNumbers = FingerNumbers.NoFinger;
                }
                else {
                    fingerNumbers = FingerNumbers.WrongState;
                }
                break;

            case FingerNumbers.TwoFingers:
                if (n == 2) {
                    ParseTwoFingerEvent();
                }
                else if (n == 0 || n == 3) {
                    fingerNumbers = FingerNumbers.NoFinger;
                }
                else {
                    fingerNumbers = FingerNumbers.WrongState;
                }
                break;

            case FingerNumbers.ThreeFingers:
                if (n == 3) {
                    ParseThreeFingerEvent();
                }
                else if (n == 0) {
                    fingerNumbers = FingerNumbers.NoFinger;
                }
                else {
                    fingerNumbers = FingerNumbers.WrongState;
                }
                break;

            default:
                // 例如用兩隻手指縮放時，一支手指突然放開，這時會進入 WrongState
                // 使用者必須放開全部的手指，讓狀態回到 NoFinger，才能接受其他事件
                if (n == 0) fingerNumbers = FingerNumbers.NoFinger;
                break;
        }
    }

    void ProcessMouse(){
        Vector3 mousePos = Input.mousePosition;
        Vector2 currentFlatMousePos = new Vector2(mousePos.x, mousePos.y);
        
        //偵測目前滑鼠有沒有指到東西
        ray = twTerrainCam.ScreenPointToRay(Input.mousePosition);
        if(!Physics.Raycast(ray, out hit)){
            maybeClick = false;
            mouseDragging = false;
            return;
        }
        // Debug.Log(hit.transform.name);
        
        //滑鼠指到東西以後需要進行的行為
        if(hit.transform.name == "Terrain" || hit.transform.name.StartsWith("ToonSoldier_WW2_demo_model")){
            mouseDragOrClick(currentFlatMousePos); //拖拉地圖或是點擊地圖、點擊物件
            mouseScrolling(); //滑鼠滾輪縮放地圖
        }
    } 

    void mouseScrolling(){
        var scrolling = Input.GetAxis("Mouse ScrollWheel");
        // Debug.Log("mouse:" + scrolling.ToString());
        
        if(scrolling < 0){
            taiwanMap.rangeScale = Mathf.Min(2.0f, taiwanMap.rangeScale + 0.05f);
        }else if (scrolling > 0) {
            taiwanMap.rangeScale = Mathf.Max(0.5f, taiwanMap.rangeScale - 0.05f);
        }else{
            return;
        }
    }

    void mouseDragOrClick(Vector2 currentFlatMousePos){
        //滑鼠左鍵點下後抓取滑鼠位置，並且開始判斷是拖曳或是點擊
        if(mouseDragging){
            Vector2 diffScreen = currentFlatMousePos - startClipPos;
            if(diffScreen.x + diffScreen.y != 0f){ //滑鼠從點下到放開有移動就視為拖曳
                Vector2 diffRelative = new Vector2(diffScreen.x / Screen.width, diffScreen.y / Screen.height);
                Vector2 diff = startDragingPos - diffRelative * taiwanMap.terrainSize * taiwanMap.rangeScale;
                taiwanMap.newPos = ((int) diff.x, (int) diff.y);
                maybeClick = false; //如果是拖曳就不是點擊
            }
            
        }

        if(Input.GetMouseButtonDown(0)){
            startDragingPos = new Vector2(taiwanMap.newPos.x, taiwanMap.newPos.y);
            startClipPos = currentFlatMousePos ;
            mouseDragging = true ;
            maybeClick = true;
        }

        if(Input.GetMouseButtonUp(0)){
            if(maybeClick){ //點擊滑鼠就是放士兵或收士兵
                if(hit.transform.name == "Terrain"){ //點在圖台上表示放士兵
                    float terrainRatio = taiwanMap.terrainSize * taiwanMap.rangeScale;
                    (int x, int y) terrainRayHit = ((int)(hit.point.x * terrainRatio), (int)(hit.point.z * terrainRatio));
                    (int x, int y) hitTerrainPos = (terrainRayHit.x + taiwanMap.newPos.x , terrainRayHit.y + taiwanMap.newPos.y);
                    var placeLongLat = GIS.TerrainToLonglat(hitTerrainPos);
                    var troopID = troopManager.TroopMissingID("soldier");
                    // troopManager.TroopMove("soldier", troopID, placeLongLat.lng, placeLongLat.lat);
                    messageBroker.AddTroop("soldier", troopID, placeLongLat.lng, placeLongLat.lat);
                }else if(hit.transform.name.StartsWith("ToonSoldier_WW2_demo_model")){ //點到士兵表示收士兵
                    hit.transform.gameObject.tag = "Finish" ;
                    //使用rayhit只能看到被hit到的Gameobject，但在原本的Troopmanager中採用dictionary進行Gameobject管理。
                    //直接刪除gameobject會造成錯誤。所以必須找到對應的dictionary key，透過管理系統進行刪除。這在士兵量太過
                    //龐大時效能會不好
                    string troopID = troopManager.GetDeletedSelectedTroopID();
                    messageBroker.RemoveTroop("soldier", troopID);
                }
                troopManager.redrawTroops = true;
            }
            maybeClick = false;
            mouseDragging = false;
        }
    }

    void ProcessKeys()
    {
        (int x, int y) pos = taiwanMap.newPos;
        // Debug.Log($"{Input.anyKey} {Input.GetKey(KeyCode.UpArrow)} {Input.GetKey(KeyCode.DownArrow)}");
        if (Input.GetKey(KeyCode.UpArrow)) {
            pos.y = pos.y + (int)(3 * taiwanMap.rangeScale);
        }
        if (Input.GetKey(KeyCode.DownArrow)) {
            pos.y = pos.y - (int)(3 * taiwanMap.rangeScale);
        }
        if (Input.GetKey(KeyCode.LeftArrow)) {
            pos.x = pos.x - (int)(3 * taiwanMap.rangeScale);
        }
        if (Input.GetKey(KeyCode.RightArrow)) {
            pos.x = pos.x + (int)(3 * taiwanMap.rangeScale);
        }
        if (Input.GetKey(KeyCode.PageUp)) {
            taiwanMap.rangeScale = Mathf.Max(0.5f, taiwanMap.rangeScale - 0.05f);
        }
        if (Input.GetKey(KeyCode.PageDown)) {
            taiwanMap.rangeScale = Mathf.Min(2.0f, taiwanMap.rangeScale + 0.05f);
        }
        if (Input.GetKey(KeyCode.Backslash)) {
            taiwanMap.SetWiregridEnable(true);
        }
        else if (Input.GetKey(KeyCode.Backspace)) {
            taiwanMap.SetWiregridEnable(false);
        }
        taiwanMap.newPos = pos;
    }

    void Update()
    {
        // 進入Slave狀態後，會暫停輸入3秒
        // if (Time.unscaledTime - disableInputFrom < 3.0f) return;

        ProcessFingers();
        ProcessKeys();
        ProcessMouse();

        if ((taiwanMap.newPos != taiwanMap.prevPos) || (taiwanMap.rangeScale != taiwanMap.prevScale)){
            messageBroker.MoveMapPosition();
            troopManager.redrawTroops = true;
            
        }
    }
}
