function generateInit(filename, rows, cols)
matrix = rand(rows,cols) > 0.5;

dlmwrite(filename,rows);
dlmwrite(filename,cols,'-append');
dlmwrite(filename,matrix,'-append','delimiter',' ');
end