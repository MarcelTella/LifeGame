sizes = [100 500 1000 2000 3000 4000];
sizes = sizes.^2;
non_par =                   [0.5881 14.6416 62.4855 234.7359 505.0320 901.9655];
par_shared_eight_cores =    [0.6313 10.7058 42.1577 177.2309 379.2330 725.9654];
par_shared_four_cores =     [0.5038 11.6601 46.4445 180.6442 409.2741 764.9343];
par_private_eight_cores =   [0.6050 14.9277 46.8162 186.6413 425.4854 747.9133];
par_private_four_cores =    [0.450674 11.3307 42.6490 158.029221 361.25 682.4041];


figure(1);
hold on;
plot(sizes,non_par,'r--o','LineWidth',2);
plot(sizes, par_shared_eight_cores,'b--o','LineWidth',2);
plot(sizes, par_private_eight_cores,'k--o','LineWidth',2);
plot(sizes, par_shared_four_cores,'y--o','LineWidth',2);
plot(sizes, par_private_four_cores,'g--o','LineWidth',2);

ylabel('time (s)');
xlabel('Number of cells');
title('Parallel performance of the Game of Life');
legend('1 core', ...
'8 cores using the share keyword', ...
'8 cores using the private keyword',...
'4 cores using the share keyword',...
'4 cores using the private keyword'...
);
hold off;
figure(2);
hold on;
plot(sizes, non_par./par_shared_eight_cores,'b--o','LineWidth',2);
plot(sizes, non_par./par_private_eight_cores,'k--o','LineWidth',2);
plot(sizes, non_par./par_shared_four_cores,'y--o','LineWidth',2);
plot(sizes, non_par./par_private_four_cores,'g--o','LineWidth',2);

ylabel('Speedup time X cores / time 1 core (s)');
xlabel('Number of cells');
title('Parallel performance of the Game of Life');
legend( ...
'8 cores using the share keyword', ...
'8 cores using the private keyword',...
'4 cores using the share keyword',...
'4 cores using the private keyword'...
);