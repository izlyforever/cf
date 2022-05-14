git $*

for ele  in ./*; do
	if [[ -d $ele ]] && [[ -d $ele/.git ]]; then
		echo "---------------------------------------"
    echo "$ele"
		cd  $ele
		git $*
		cd ..
	fi
done
