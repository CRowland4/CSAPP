/* Exercise 1.1

Total Distance: 2,500 km
Average Speed: 100 km/hr
Trip Time: 25 hr


A. New Speed Limit: Can now drive 150km/hr for 1,500 km.

    With Amdahl's Law, α = 1,500/2,500 = 0.6, and the speed during this leg went from 100 km/hr to 150 km/hr, an increase by a factor of k = 1.5.

    Then S = 1 / ((1 - 0.6) + (0.6 / 1.5) = 1.25, so we get a speedup of 1.25x.

B. Here we replace 1.25 with k, set S = 1.67, and solve for k.

    So 1 / ((1 - 0.6) + (0.6 / k)) = 1.67 --> k = 3.02, so we'll need to go 3.02 * 100 = 302 km/hr for that 1,500 km in order to get an overall speedup of 1.67x.

*/



/*
Exercise 1.2

Performance increase of 2x, so S = 2.

80% of the system can be improved, so α = 0.8.

Then 1 / ((1 - 0.8) + (0.8 / k)) = 2, and solving for k gives k = 2.67.

So this 80% of the system will be able to be improved by a factor of 2.67.

*/