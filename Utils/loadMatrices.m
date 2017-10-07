function images = loadMatrices(filename, nRows, nCols)
    fid = fopen(filename);
    data = fscanf(fid, '%d', [nRows*nCols, inf])';
    
    nIterations = size(data, 1);
    images = cell(nIterations, 1);
    for i = 1:nIterations
       % The ' because of the way fscanf reads the data. Read in column
       % order.
       images{i} = reshape(data(i, :), nRows, nCols, 1)'; 
    end
    fclose(fid);  
end