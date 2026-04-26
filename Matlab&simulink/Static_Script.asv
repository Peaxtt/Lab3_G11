% 1. Load the MAT file
fileName = '5nut_KalmanforEstimate.mat';
fprintf('Loading data from %s...\n', fileName);
data = load(fileName);

% 2. Extract the raw/reference data
% Based on your image, the reference variable is 'Pitch'
raw_var_name = 'data'; 

all_names = {};
all_rmse = [];
all_r2 = [];
    
if isfield(data, raw_var_name)
    % Extract the numerical data array from the timeseries object
    raw_signal = data.(raw_var_name){11}.Values.Data; 
else
    error('Variable "%s" not found in the MAT file.', raw_var_name);
end

% 3. Extract all variable names from the loaded file
varNames = fieldnames(data);
% Pre-calculate the Total Sum of Squares (SST) for R-squared
mean_raw = mean(raw_signal(:));
SST = sum((raw_signal(:) - mean_raw).^2);
% 4. Initialize tracking variables
best_pair = '';
min_error = inf;
all_pairs = {};
all_errors = [];

fprintf('\nCalculating RMSE for all (Q, R) pairs compared to "Pitch"...\n');
fprintf('----------------------------------------------------------\n');

figure('Name', 'All Kalman Filter Results vs Raw_Read', 'Color', 'black');
hold on; % Keep the plot window open to add multiple lines
grid on;

varName = data.data{11};

 t = varName.Values.Time;
 y = varName.Values.Data;
 plot(t, y, 'LineWidth', 0.01,'DisplayName', varName.Name,'LineWidth', 2.5,'Color', 'green');

% 5. Loop through all variables
for i = 2:11
    varName = data.data{i};
    
% Extract Time and Data from the timeseries object
        t = varName.Values.Time;
        y = varName.Values.Data;
        % Extract the numerical data from the filtered timeseries object
        
        
       
        plot(t, y, 'LineWidth', 0.01,'DisplayName', data.data{i}.Name);
       
        % Extract the numerical data from the filtered timeseries object
        filtered_signal = varName.Values.Data;
        
   
            
            % Calculate Root Mean Squared Error (RMSE)
            % Formula: sqrt( mean( (Actual - Filtered)^2 ) )
            current_error = sqrt(mean((raw_signal(:) - filtered_signal(:)).^2));
            SSR = sum((raw_signal(:) - filtered_signal(:)).^2);
    current_r2 = 1 - (SSR / SST);
           
            
            
            fprintf('Metrics for %s -> RMSE: %f | R^2: %f\n', data.data{i}.Name, current_error, current_r2);
            
            % Track the best pair (lowest error)
            if current_error < min_error
                min_error = current_error;
                best_pair = varName;
            end

            % Store for the bar charts and table
    all_names{end+1} = data.data{i}.Name;
    all_rmse(end+1) = current_error;
    all_r2(end+1)  = current_r2;
        
end

t_raw = data.data{11}.Values.Time;
    y_raw = data.data{11}.Values.Data;
    
    % Plot in black ('k') with a thicker line to stand out
    %plot(t_raw, y_raw, 'k', 'LineWidth', 2.5, 'DisplayName', 'Distance (Raw Data)');
hold off;

% 5. Format the plot with titles, labels, and the legend
title('Kalman Filter Tuning: All Estimations vs. Raw read');
xlabel('Time ( s )');
ylabel('Distance ( cm )');

Filter_Pair = string(all_names'); % Convert to string array for cleaner table display
RMSE = all_rmse';
R_Squared = all_r2';

% Create the table
results_table = table(Filter_Pair, RMSE, R_Squared);


% ==========================================================
% 6. VISUALIZE RMSE AS A BAR CHART
% ==========================================================
figure('Name', 'RMSE Comparison', 'Color', 'w');
bar(all_rmse, 'FaceColor', [0.2 0.6 0.8]);
set(gca, 'XTickLabel', strrep(all_names, '_', '\_'), 'XTick', 1:length(all_names));
xtickangle(45); 
ylabel('Root Mean Square Error (RMSE)');
xlabel('Kalman Filter Tuning Pairs');
title('RMSE Comparison: Lower is Better');
grid on;

hold on;
% --- NEW MEDIAN LOGIC ---
% 1. Calculate the exact median of all RMSE values
target_median = median(all_rmse);

% 2. Find the tuning pair that is exactly equal to (or closest to) this median
% We do this by finding the minimum absolute difference from the median
[~, best_idx] = min(abs(all_rmse - target_median));
bar(best_idx, all_rmse(best_idx), 'FaceColor', [0.8 0.2 0.2]);
legend('All Pairs', 'Best Pair (Lowest RMSE)', 'Location', 'best');
hold off;

%% Pre-process for estiamte
b=3e-02
k=28.10
M=0.2608
%start_idx = 2000000+(11.8*1000);
%end_idx = 3000000+(11.8*1000);

start_idx = (5.152)*1000;
end_idx =29.817*1000;
fileName = '1nut_KalmanforEstimate.mat';
fprintf('Loading data from %s...\n', fileName);
Test_Estimate_data = load(fileName);

Preprocess=Test_Estimate_data.data{10}.Values.Data-Test_Estimate_data.data{10}.Values.Data(end)-0.4;
PreprocessTime=Test_Estimate_data.data{10}.Values.Time;
Preprocess_rawdata=Test_Estimate_data.data{11}.Values.Data-Test_Estimate_data.data{11}.Values.Data(end);
% Extract full Time and Data
    t_full = PreprocessTime;
    y_full = Preprocess;
   
    % Slice the Time and Data to only get the selected range
    t = t_full(start_idx:end_idx);
    t = t-t(1);
    filtered_signal = y_full(start_idx:end_idx);
    filtered_signal=double(filtered_signal);
filtered_signal=filtered_signal/100.00;
    
%plot(SDOSimTest_Log.simout.Time,SDOSimTest_Log.simout.Data);
%plot(PreprocessTime,Preprocess_rawdata);
%plot(Test_Estimate_data.data{11}.Values.Time,Test_Estimate_data.data{11}.Values.Data);
    hold on;
   % plot(PreprocessTime,Preprocess);
    plot(t, filtered_signal);
    %plot(t,filtered_signal);
    hold off;
%% % =========================================================================
% =========================================================================
% 1. DATA PREPARATION
% =========================================================================

mass_array = [0.148,0.1856,0.2232,0.260,0.2984,0.336,0.336+0.0376]; 

% Define the estimated damping (b) AND stiffness (k) parameters
b_array = [0.046648, 0.031891, 0.027714, 0.050868, 0.035322, 0.047588]; 
k_array = [28.929, 29.163, 29.12, 29.046, 29.041, 29.255]; 

% Initialize cell arrays to store the data
raw_data_cell = cell(1, 6);
time_cell = cell(1, 6);
x0_array = zeros(1, 6);
stop_times = zeros(1, 6);

fprintf('Loading Data and Setting Initial Conditions...\n');

for i = 1:6
    file_name = sprintf('filtersignal_%dnut.mat', i);
   load(file_name); 
    current_data = filtered_signal;
    
    file_name = sprintf('t_%dnut.mat', i);
    load(file_name);
    current_time = t;
    
    % --- EXTRACT INITIAL CONDITION (x0) ---
    x0_array(i) = current_data(1); 
    
    % Store the processed data
    raw_data_cell{i} = current_data;
    time_cell{i} = current_time;
    
    % Calculate Stop Time
    stop_times(i) = current_time(end); 
end

% =========================================================================
% 2. BATCH SIMULATION SETUP
% =========================================================================
model_name = 'MassSpringDamper_model';
load_system(model_name); 

num_sims = 36;
simIn(num_sims) = Simulink.SimulationInput(model_name);

fprintf('Configuring %d Simulations for Batch Processing...\n', num_sims);

idx = 1;
for i = 1:6 % Mass / Raw Data loop
    for j = 1:6 % Estimated Parameter Set (b, k) loop
        
        simIn(idx) = Simulink.SimulationInput(model_name);
        
        % Inject mass, x0, and BOTH estimated parameters (b and k)
        simIn(idx) = simIn(idx).setVariable('M', mass_array(i));
        simIn(idx) = simIn(idx).setVariable('current_x0', x0_array(i));
        simIn(idx) = simIn(idx).setVariable('b', b_array(j));
        simIn(idx) = simIn(idx).setVariable('k', k_array(j)); % NEW: Inject k
        
        % Set custom stop time
        simIn(idx) = simIn(idx).setModelParameter('StopTime', num2str(stop_times(i)));
        
        idx = idx + 1;
    end
end

% =========================================================================
% 3. RUN ALL SIMULATIONS IN PARALLEL
% =========================================================================
fprintf('Running Simulations...\n');
simOut = parsim(simIn, 'ShowProgress', 'on', 'UseFastRestart', 'on');

% =========================================================================
% 4. EXTRACT RESULTS & CALCULATE ERRORS
% =========================================================================
rmse_matrix = zeros(6, 6);
r2_matrix = zeros(6, 6);

idx = 1;
for i = 1:6
    current_raw_data = raw_data_cell{i};
    SST = sum((current_raw_data(:) - mean(current_raw_data(:))).^2); 
    
    for j = 1:6
        simulated_distance = simOut(idx).simout.Data;

        min_length = min(length(current_raw_data), length(simulated_distance));
        raw_trimmed = current_raw_data(1:min_length);
        sim_trimmed = simulated_distance(1:min_length);
        
        % Calculate Metrics
        rmse_matrix(i, j) = sqrt(mean((raw_trimmed(:) - sim_trimmed(:)).^2));
        SSR = sum((raw_trimmed(:) - sim_trimmed(:)).^2);
        r2_matrix(i, j) = 1 - (SSR / SST);
        
        idx = idx + 1;
    end
end

% =========================================================================
% 5. VISUALIZATION
% =========================================================================
Row_Names = {'1 nut'; '2 nut'; '3 nut'; '4 nut'; '5 nut'; '6 nut'};
Var_Names = {'Parameter set 1', 'Parameter set 2', 'Parameter set 3', 'Parameter set 4', 'Parameter set 5', 'Parameter set 6'};

% Display Tables
disp('==================== RMSE CROSS-VALIDATION TABLE ====================');
disp(array2table(rmse_matrix, 'RowNames', Row_Names, 'VariableNames', Var_Names));

disp('==================== R-SQUARED CROSS-VALIDATION TABLE ====================');
disp(array2table(r2_matrix, 'RowNames', Row_Names, 'VariableNames', Var_Names));

% Heatmaps
figure('Name', 'Cross-Validation Results', 'Color', 'w', 'Position', [100, 100, 1200, 500]);

subplot(1, 2, 1);
heatmap(Var_Names, Row_Names, rmse_matrix, 'Colormap', parula, ...
    'Title', 'RMSE (Lower is Better)', 'XLabel', 'Parameter Set Used (b, k)', 'YLabel', 'Physical Mass Tested');

subplot(1, 2, 2);
heatmap(Var_Names, Row_Names, r2_matrix, 'Colormap', summer, ...
    'Title', 'R-Squared (Closer to 1 is Better)', 'XLabel', 'Parameter Set Used (b, k)', 'YLabel', 'Physical Mass Tested');

% =========================================================================
% 6. CALCULATE AVERAGES TO FIND THE BEST OVERALL PARAMETER SET
% =========================================================================

% Calculate the average across the rows (dimension 1) for each column
avg_rmse = mean(rmse_matrix, 1);
avg_r2 = mean(r2_matrix, 1);

% Find the index of the best values
% For RMSE, we want the minimum value
[min_avg_rmse, best_rmse_idx] = min(avg_rmse);

% For R^2, we want the maximum value (the one closest to 1, or the least negative)
[max_avg_r2, best_r2_idx] = max(avg_r2);

% Get the names of the winning parameter sets
best_set_rmse = Var_Names{best_rmse_idx};
best_set_r2 = Var_Names{best_r2_idx};

% Format the data for a summary table
Parameter_Set = Var_Names'; % Transpose to a column
Average_RMSE = avg_rmse';
Average_R_Squared = avg_r2';

avg_table = table(Parameter_Set, Average_RMSE, Average_R_Squared);

% Display the results
disp(' ');
disp('================ AVERAGE METRICS PER PARAMETER SET ================');
disp(avg_table);
disp('-------------------------------------------------------------------');
fprintf('>> BEST SET OVERALL (By Lowest Avg RMSE): %s (Value: %.4f)\n', best_set_rmse, min_avg_rmse);
fprintf('>> BEST SET OVERALL (By Highest Avg R^2): %s (Value: %.4f)\n', best_set_r2, max_avg_r2);
disp('===================================================================');

% =========================================================================
% 7. PLOT ALL 36 CROSS-VALIDATION SCENARIOS (6x6 GRID)
% =========================================================================
fprintf('Generating 6x6 Plot Grid...\n');

figure('Name', 'All 36 Cross-Validation Plots', 'Color', 'w', 'Units', 'normalized', 'Position', [0.05, 0.05, 0.9, 0.9]);
t = tiledlayout(6, 6, 'TileSpacing', 'compact', 'Padding', 'compact');
title(t, 'Raw Data (Yellow) vs. Simulated Estimation (Blue) | Rows = Mass Tested, Cols = Parameter Set', 'FontWeight', 'bold', 'FontSize', 14);

idx = 1;
for i = 1:6 % Rows: Physical Mass / Raw Data
    
    current_raw_data = raw_data_cell{i};
    current_time = time_cell{i};
    
    for j = 1:6 % Columns: Parameter Set (b, k)
        
        % --- UPDATED EXTRACTION LINES ---
        sim_signal = simOut(idx).simout.Data;
        sim_time = simOut(idx).simout.Time;
        
        nexttile;
        hold on;
        grid on;
        
        plot(current_time, current_raw_data, 'y', 'LineWidth', 1.5, 'DisplayName', 'Raw Sensor');
        plot(sim_time, sim_signal, 'b--', 'LineWidth', 1.5, 'DisplayName', 'Simulation');
        
        title(sprintf('Mass: %dkg | Param Set: %d', mass_array(i), j), 'FontSize', 9);
        
        if idx == 1
            legend('Location', 'best', 'FontSize', 8);
        end
        
        if i == 6
            xlabel('Time (s)', 'FontSize', 8);
        else
            xticklabels({});
        end
        
        if j == 1
            ylabel('Distance ( m )', 'FontSize', 8);
        else
            yticklabels({});
        end
        
        hold off;
        idx = idx + 1;
    end
end


% =========================================================================
% 8. PLOT BAR CHARTS FOR AVERAGE RMSE AND R-SQUARED
% =========================================================================
fprintf('Generating Bar Charts for Averages...\n');

% ---------------------------------------------------------
% FIGURE 1: Average RMSE Bar Chart (Lower is Better)
% ---------------------------------------------------------
figure('Name', 'Average RMSE Comparison', 'Color', 'w');
% Plot all bars in a standard blue color
bar(avg_rmse, 'FaceColor', [0.2 0.6 0.8]); 
hold on;

% Highlight the best (lowest) RMSE in Red
bar(best_rmse_idx, avg_rmse(best_rmse_idx), 'FaceColor', [0.8 0.2 0.2]); 

% Format the chart
set(gca, 'XTickLabel', strrep(Var_Names, '_', '\_'), 'XTick', 1:length(Var_Names));
xtickangle(45);
ylabel('Average RMSE');
xlabel('Parameter Set Used (b, k)');
title('Average RMSE Across All Masses (Lower is Better)');
grid on;

% Add legend with the specific winning name
legend('All Sets', sprintf('Best Set (%s)', strrep(best_set_rmse, '_', '\_')), 'Location', 'best');
hold off;


% ---------------------------------------------------------
% FIGURE 2: Average R-Squared Bar Chart (Higher is Better)
% ---------------------------------------------------------
figure('Name', 'Average R-Squared Comparison', 'Color', 'w');
% Plot all bars in a standard green color to differentiate from RMSE
bar(avg_r2, 'FaceColor', [0.2 0.8 0.4]); 
hold on;

% Highlight the best (highest) R-Squared in Red
bar(best_r2_idx, avg_r2(best_r2_idx), 'FaceColor', [0.8 0.2 0.2]); 

% Format the chart
set(gca, 'XTickLabel', strrep(Var_Names, '_', '\_'), 'XTick', 1:length(Var_Names));
xtickangle(45);
ylabel('Average R-Squared');
xlabel('Parameter Set Used (b, k)');
title('Average R-Squared Across All Masses (Higher is Better)');
grid on;

% Add legend with the specific winning name
legend('All Sets', sprintf('Best Set (%s)', strrep(best_set_r2, '_', '\_')), 'Location', 'best');
hold off;