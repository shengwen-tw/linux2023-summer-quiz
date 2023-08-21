data = csvread('perf.csv');
size    = data(:, 1);
st_time = data(:, 2);
rb_time = data(:, 3);

grid on
plot(size, st_time, size, rb_time);
legend('S-Tree', 'Red Black Tree');

xlabel('Node numbers');
ylabel('Nanoseconds');

pause;
