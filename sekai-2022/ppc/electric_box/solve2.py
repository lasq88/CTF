import sys
import math

radius, n_layers = list(map(int,sys.stdin.readline().strip().split()))
layers_sizes = list(map(int,sys.stdin.readline().strip().split()))
tun_l, tun_h, n_obs = list(map(int,sys.stdin.readline().strip().split()))

obstacles = []
for obs in range(n_obs):
    obstacles.append(list(map(int,sys.stdin.readline().strip().split())))

def isColliding(c1, c2):
    d = math.sqrt(math.pow(c1[0] - c2[0], 2) + math.pow(c1[1] - c2[1], 2)) - c1[2]
    return d <= 0

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

    if radius*2 >= tun_h:
        print(-1)
        return 0

    max_dist = tun_h
    if (n_obs > 0):
        for x in range(tun_l):
            distances = []
            temp_dist = 0
            for y in range(tun_h):
                collision = False
                for o in obstacles:
                    if o[0] - o[2] >= x or o[0] + o[2] <= x:
                        collision = isColliding(o,[x,y])
                if collision or (y == tun_h-1):
                    if temp_dist > 0:
                        distances.append(temp_dist)
                        temp_dist = 0
                        break
                else:
                    temp_dist = temp_dist + 1
            x_max = max(distances)
            if x_max < max_dist:
                max_dist = x_max


    print("Max distance: {}".format(max_dist))
    for b in possible_ball_sizes:
        if b >= max_dist:
            max_size = possible_ball_sizes[possible_ball_sizes.index(b)-1]
            break

    #print("Max size: {}".format(max_size))
    #print(possible_ball_sizes.index(max_size))
    return 0

if __name__ == "__main__":
    main()