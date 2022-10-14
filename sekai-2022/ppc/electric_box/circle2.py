import matplotlib.pyplot as plt
 


figure, axes = plt.subplots()

circle1 = plt.Circle( (0.2000, 0.0050 ),0.0050, fill = False )
circle2 = plt.Circle( (0.2110, 0.0250 ),0.0050, fill = False )
circle3 = plt.Circle( (0.2220, 0.0450 ),0.0050, fill = False )

axes.set_aspect( 1 )
axes.add_artist( circle1 )
axes.add_artist( circle2 )
axes.add_artist( circle3 )
plt.show()