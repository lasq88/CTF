import sys
import math

radius, n_layers = list(map(int,sys.stdin.readline().strip().split()))
layers_sizes = list(map(int,sys.stdin.readline().strip().split()))
tun_l, tun_h, n_obs = list(map(int,sys.stdin.readline().strip().split()))

obstacles = []
for obs in range(n_obs):
    obstacles.append(list(map(int,sys.stdin.readline().strip().split())))
obstacles.sort()

def findDistance(c1, c2):
    d = math.sqrt(math.pow(c1[0] - c2[0], 2) + math.pow(c1[1] - c2[1], 2)) - (c1[2] + c2[2])
    return d

def findTopBottom():
    min_bot = min_top = tun_h
    for o in obstacles:
        min_bot = min(findDistance((o[0],0,0),o),min_bot)
        min_top = min(findDistance((o[0],tun_h,0),o),min_top)
    return min_bot, min_top

def findMid():
    dist = 0
    for i in range(n_obs-1):
        if (obstacles[i][0] + obstacles[i][2]) - (obstacles[i+1][0] - obstacles[i+1][2]) >= 0:
            dist = max(findDistance(obstacles[i],obstacles[i+1]),dist)
    return dist

def main():
    layers_sizes.sort()
    #print(radius, n_layers)
    #print(layers_sizes)
    #print(tun_l, tun_h, n_obs)
    print(obstacles)
    possible_ball_sizes = [radius*2]

    for i in range(len(layers_sizes)):
        possible_ball_sizes.append(possible_ball_sizes[i] + layers_sizes[i] * 2)

    print("Ball sizes: {}".format(possible_ball_sizes))

    if n_obs > 0:
        min_bot, min_top = findTopBottom()
    else:
        min_bot = min_top = tun_h
    
    if n_obs > 1:
        mid = findMid()
    else:
        mid = 0
    print(min_bot, mid, min_top)
    max_dist = max(min_bot, mid, min_top)


    print("Max distance: {}".format(max_dist))
    if max_dist <= possible_ball_sizes[0]:
        print(-1)
        return 0
    else:
        for b in possible_ball_sizes:
            if b >= max_dist:
                max_size = possible_ball_sizes[possible_ball_sizes.index(b)-1]
                break
            max_size = possible_ball_sizes[-1]

    print("Max size: {}".format(max_size))
    print(possible_ball_sizes.index(max_size))
    return 0


if __name__ == "__main__":
    main()