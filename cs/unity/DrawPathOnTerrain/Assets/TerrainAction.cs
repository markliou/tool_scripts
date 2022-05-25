using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TerrainAction : MonoBehaviour
{
    Terrain terrain ;
    TerrainData terrainData;
    Camera mainCamera;
    InputManager inputMag ;

    Ray ray;
    RaycastHit hit;
    public string hitObjName;
    
    void Awake(){
        terrain = FindObjectOfType<Terrain>();
        mainCamera = FindObjectOfType<Camera>();
        inputMag = FindObjectOfType<InputManager>();
        terrainData = terrain.terrainData;

        // Debug.Log(terrain.name);
        // Debug.Log(mainCamera.name);
    }

    // Start is called before the first frame update
    void Start()
    {
        //整張地圖變成平的
        float[,] newHeights = terrainData.GetHeights(0,0,terrainData.heightmapWidth, terrainData.heightmapHeight);
        for(int x=0 ; x<terrainData.heightmapWidth; x++){
            for(int y=0; y<terrainData.heightmapHeight; y++){
                newHeights[x,y] = 0f;
            }
        }
        terrainData.SetHeights(0, 0, newHeights);
    }

    // Update is called once per frame
    void Update()
    {
        ray = mainCamera.ScreenPointToRay(Input.mousePosition);
        if (Physics.Raycast(ray, out hit))  // 如果ray觸及任何Collider
        {
            // hitObjName = hit.transform.name;
            // Debug.Log(hit.transform.name);
            // Debug.Log(hit.point); //give (x,y,height)

            Vector3 pointTerrainData = hit.point;
            // Debug.Log(terrainData.GetHeights(0,0,terrainData.heightmapWidth, terrainData.heightmapHeight));
            // Debug.Log(terrainData.heightmapWidth);
            // Debug.Log(terrainData.heightmapResolution);
            
            //滑鼠經過的地方突起
            var offSet = terrain.GetPosition();
            // Debug.Log(offSet);
            // Debug.Log(hit.point);
            // Debug.Log(terrainData.size.x);
            // Debug.Log(terrainData.heightmapWidth);
            // Debug.Log(terrainData.heightmapHeight);
            // Debug.Log(terrainData.heightmapResolution);
            // Debug.Log((int)(((hit.point.x - offSet.x) / terrainData.size.x) * terrainData.heightmapResolution));
            float[,] newHeights = terrainData.GetHeights(0,0,terrainData.heightmapWidth, terrainData.heightmapHeight);
            int _tx = (int)(((hit.point.x - offSet.x) / terrainData.size.x) * terrainData.heightmapResolution) ;
            int _tz = (int)(((hit.point.z - offSet.z) / terrainData.size.z) * terrainData.heightmapResolution) ;
            newHeights[_tz, _tx] += .1f;
            terrainData.SetHeights(0, 0, newHeights);
            

        }
    }
}
