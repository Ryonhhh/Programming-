#-----------------------------------------------------------------------
# universe.py
#-----------------------------------------------------------------------

import sys
import stdarray
from body import Body 
from instream import InStream
from vector import Vector
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

#-----------------------------------------------------------------------

class Universe:

    # Construct a new Universe object by reading a description
    # from the file whose name is filename.

    def __init__(self, filename):
        instream = InStream(filename)
        n = instream.readInt()
        radius = instream.readFloat()
        self._bodies = stdarray.create1D(n)
        for i in range(n):
            rx   = instream.readFloat()
            ry   = instream.readFloat()
            rz   = instream.readFloat()
            vx   = instream.readFloat()
            vy   = instream.readFloat()
            vz   = instream.readFloat()
            mass = instream.readFloat()
            r = Vector([rx, ry, rz])
            v = Vector([vx, vy, vz])
            self._bodies[i] = Body(r, v, mass)

    # Simulate the passing of dt seconds in self.
    
    def increaseTime(self, dt):
        
        # Initialize the forces to zero.
        n = len(self._bodies)
        f = stdarray.create1D(n, Vector([0, 0, 0]))
        
        # Compute the forces.
        for i in range(n):
            for j in range(n):
                if i != j:
                    bodyi = self._bodies[i]
                    bodyj = self._bodies[j]
                    f[i] = f[i] + bodyi.forceFrom(bodyj)

        # Move the bodies.
        for i in range(n):
            self._bodies[i].move(f[i], dt)    

    # Draw self to standard draw.
    def draw(self, ax):
        #for body in self._bodies:
            #body.draw(ax, "blue")
        n = len(self._bodies)
        self._color = stdarray.create1D(4)
        self._color[0] = "blue"
        self._color[1] = "red"
        self._color[2] = "green"
        self._color[3] = "yellow"
        mass0 = self._bodies[0]._mass
        for i in range(n):
            if self._bodies[i]._mass > mass0:
                mass0 = self._bodies[i]._mass
        for i in range(n):
            bodyx = self._bodies[i]
            bodyx.draw(ax, self._color[i] , bodyx._mass/mass0 * 100)

#-----------------------------------------------------------------------

# Accept a string filename and a float dt as command-line arguments.
# Simulate the motion in the universe defined by the contents of
# the file with the given filename, increasing time at the rate
# specified by dt.

def main():
    filename = sys.argv[1]
    dt = float(sys.argv[2]) * 5e3
    universe = Universe(filename)
    fig = plt.figure()
    ax = Axes3D(fig)
    ax.set_facecolor("black")

    while True:
        universe.increaseTime(dt)
        universe.draw(ax)
        ax.set_xlim3d(-5e10, 5e10)
        ax.set_ylim3d(-5e10, 5e10)
        ax.set_zlim3d(-5e10, 5e10)
        plt.pause(0.000001)
        plt.cla()


if __name__ == '__main__':
    main()

#-----------------------------------------------------------------------

# python universe.py 2bodyTiny.txt 20000

# python universe.py 2body.txt 20000

# python universe.py 3body.txt 20000

# python universe.py 4body.txt 20000
