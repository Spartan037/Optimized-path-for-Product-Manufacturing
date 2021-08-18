# Optimized-path-for-Product-Manufacturing

<br><h3>Abstract</h3>
<br>Assembly line scheduling helps us to understand and know how tasks are
to be assigned to workstations, so that the predetermined goal is achieved.
Minimization of the number of workstations and maximization of the production
rate are the most common goals. This project thus addresses the problem of
scheduling the cloth manufacturing unit's time on identical parallel machines
(assembly lines) to minimize total weighted time required for manufacturing
using Dynamic Programming.
Dynamic Programming uses a bottom up approach to build up the final
solution. The solution of a problem is formulated recursively in terms of sub
problems however we construct the solution for the bigger problem by first
solving the smaller problems then combining the solutions of the sub problems
and examining a model that incorporates the efficiency/timeliness conflict in
practice. We propose properties of an optimal solution for the purpose of
exposing to reduce the total time required for the production in the cloth
production unit.
<br><br><h3>Problem Statement</h3>
A cloth manufacturing company has, for example two assembly lines, each
with n stations. A station is denoted by Si,j where i denotes the assembly line the
station is on and j denotes the number of the station. The time taken per station is
denoted by ai,j . Each station is dedicated to do some sort of work in the
manufacturing process. So, a cloth must pass through each of the n stations in
order before exiting the company. The parallel stations of the two assembly lines
perform the same task. After it passes through station Si,j , it will continue to
station Si,j+1 unless it decides to transfer to the other line. Continuing on the same
line incurs no extra cost, but transferring from line i at station j − 1 to station j on
the other line takes time ti,j . Each assembly line takes an entry time ei and exit
time x.
<br><br><h2> Technologies Used </h2>
<br><b> Languages:</b> C++
