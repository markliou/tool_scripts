using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InputManager : MonoBehaviour
{
    Terrain terrain ;
    TerrainData terrainData;
    Camera mainCamera;
    
    Camera twTerrainCam;
    Ray ray;
    RaycastHit hit;
    string hitObjName;

    void Awake()
    {
        terrain = FindObjectOfType<Terrain>();
        mainCamera = FindObjectOfType<Camera>();
        terrainData = terrain.terrainData;

        Debug.Log(terrain.name);
        Debug.Log(mainCamera.name);
    }

    // Update is called once per frame
    void Update()
    {
        // ray = mainCamera.ScreenPointToRay(Input.mousePosition);
        // if (Physics.Raycast(ray, out hit))  // 如果ray觸及任何Collider
        // {
        //     hitObjName = hit.transform.name;
        //     Debug.Log(hit.transform.name);
        //     Debug.Log(hit.point);
        // }
    }
}
