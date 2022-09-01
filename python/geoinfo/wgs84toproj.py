import numpy as np 

# reference: https://developers.google.com/maps/documentation/javascript/examples/map-coordinates?hl=de
# note:
# 1. translate the latitude and longitude to the Mercator projection
# 2. split the projection in to ratster (the tiles)
# 3. using the scale (the power of 2) and the tile width to get the tile index. The google compatable map alway set the tile size as 256 * 256.

def ProjTileCoor(lnglat, zoom):
    # let siny = Math.sin((latLng.lat() * Math.PI) / 180);

    # // Truncating to 0.9999 effectively limits latitude to 89.189. This is
    # // about a third of a tile past the edge of the world tile.
    #  siny = Math.min(Math.max(siny, -0.9999), 0.9999);

    #  return new google.maps.Point(
    #   TILE_SIZE * (0.5 + latLng.lng() / 360),
    #   TILE_SIZE * (0.5 - Math.log((1 + siny) / (1 - siny)) / (4 * Math.PI))
    # );
    lng, lat = lnglat
    TILE_SIZE = 256.
    scale = 1 << zoom
    siny = np.sin((lat * np.pi)/180)
    siny = np.clip(siny, -0.9999, 0.9999)
    point = (TILE_SIZE * (0.5 + lng / 360), TILE_SIZE * (0.5 - np.log((1 + siny) / (1 - siny)) / (4 * np.pi)))
    print(point) # the world point in the projection
    coor = (np.floor((point[0] * scale) / TILE_SIZE), np.floor((point[1] * scale) / TILE_SIZE))
    print(coor) # use the scale information and tile size information to get the tile index
    return (int(coor[0]), int(coor[1]))
pass


def main():
    lnglat = (121.512481, 25.03997) #總統府
    z = 16
    x, y = ProjTileCoor(lnglat, z)
    
    print("https://wmts.nlsc.gov.tw/wmts/EMAP/default/GoogleMapsCompatible/{}/{}/{}".format(z,y,x))
pass

if __name__ == '__main__':
    main();
pass