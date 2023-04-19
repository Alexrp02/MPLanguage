touch tests//.timeout
CMD="valgrind --leak-check=full /home/gte/acu/Latex/Docencia/MP/MP_2022_2023/Github/MP2223/NetBeans/Language3/dist/Debug/GNU-Linux/language3  ../Books/fortunata.bgr ../Books/quijote.bgr ../Books/fortunata.bgr 1> tests//.out7 2>&1"
eval $CMD
rm tests//.timeout
