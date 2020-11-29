echo "Type the name of the scan file here (avoid spaces in name), then press <enter>"

read filename

mogrify -format tif $filename.*; convert -units PixelsPerInch ${filename%.*}.tif -density 300 Step1

echo “Processing ${filename%.*}.tif file”

tesseract ${filename%.*}.tif 'Русский-текст' -l rus

rm Step1

rm ${filename%.*}.tif