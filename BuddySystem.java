public class BuddySystem{
	/*   pure storage buddy system bitmap
    Given a complete binary tree with nodes of values of either 1 or 0, the following rules always hold:
    (1) a node's value is 1 if and only if all its subtree nodes' values are 1
    (2) a leaf node can have value either 1 or 0
    Implement the following 2 APIs:
    set_bit(offset, length), set the bits at range from offset to offset+length-1
    clear_bit(offset, length), clear the bits at range from offset to offset+length-1
    
    i.e. The tree is like:
                 0
              /     \
             0        1
           /  \      /  \
          1    0    1    1
         /\   / \   /\   /\
        1  1 1   0 1  1 1  1
        Since it's full binary tree, the nodes can be stored in an array
    */
    //first lets assume that the tree is full binary tree
	// boolean[][] bitmap = new boolean[][]{{true},{true,true},{true,true,true,true},{true,true,true,true,true,true,true,true}};
	boolean[][] bitmap = new boolean[][]{{false},{false,false},{false,false,false,false},{false,false,false,false,false,false,false,false}};	
	public void renew(){
		bitmap =  new boolean[][]{{false},{false,false},{false,false,false,false},{false,false,false,false,false,false,false,false}};	
	}
	public void print(){
		System.out.println();
		int len = bitmap[bitmap.length-1].length;
		for(int i = 0;i < bitmap.length; i++){
			for(int k = 0; k < bitmap[i].length; k++){
				if(k % 2 == 0){
					for(int j = 0; j < len; j++){
						System.out.print(" ");
					}
				}
				else{
					for(int j = 0; j < 3*len/2; j++){
						System.out.print(" ");
					}
				}
				if(bitmap[i][k] == true){
					System.out.print(1);
				}
				else{
					System.out.print(0);
				}
			}
			System.out.println();
			len = len/2;
		}
	}
	public void clearBit(int offset, int len){
		clearBitHelper(offset,offset+len-1,bitmap.length-1);
	}

	public void clearBitHelper(int offset,int end, int lvl){
		if(end> bitmap[lvl].length || (end-offset) < 0){
			System.out.println("Wrong parameter");
		}
		// System.out.println("offset "+offset+" "+"end"+ " "+end+" "+" lvl "+lvl);
		for(int i = offset; i <= end; i++){
			bitmap[lvl][i] = false;
		}
		//need to set the ancestor
		if(lvl == 0){
			return;
		}
		clearBitHelper(offset/2,end/2,lvl-1);

	}

	//Improved clear bit ,by checking if the bit is already cleared
	public void clearBit2(int offset,int len){
		clearBitHelper2(offset,offset+len-1,bitmap.length-1);
	}
	public void clearBitHelper2(int offset, int end, int lvl){
		if(end> bitmap[lvl].length || (end-offset) < 0){
			System.out.println("Wrong parameter");
		}
		boolean advance = false;
		for(int i = offset; i <= end; i++){
			if(bitmap[lvl][i] == false){
				if(i % 2== 0){
					advance = true;
				}
				else{
					offset = offset+ offset % 2== 0?2:1; 
					advance = false;
				}
			}
			else{
				if(i % 2 != 0 && advance == true){
					offset = offset+ offset % 2== 0?2:1; 
					advance = false;
				}
				bitmap[lvl][i] = false;
			}
		}
		//need to set the ancestor
		if(lvl == 0){
			return;
		}
		clearBitHelper(offset/2,end/2,lvl-1);
	}
	public void setBit(int offset, int len){
		setBitHelper(offset,len+offset-1,bitmap.length-1);
	}
	public void setBitHelper(int offset, int end, int lvl){
		System.out.println("offset "+offset+" end "+end+" lvl "+lvl);
		if(end >= bitmap[lvl].length || offset > end){
			return;
		}
		if(offset % 2 != 0){
			//start node is the right node , we need to consider whether the left node is true or false
			//edge cases
			if(bitmap[lvl][offset-1] == false){
				bitmap[lvl][offset] = true;
				offset++;
			}
		}
		//end node is the left node, we need to consider whether the right node is true or false
		if(end % 2 == 0){
			if(bitmap[lvl][end+1] == false){
				bitmap[lvl][end] = true;
				end--;
			}	
		}
		for(int i = offset; i <= end; i++){
			bitmap[lvl][i] = true;
		}
		if(lvl == 0){
			return;
		}
		if(end < 0 || offset >= bitmap[lvl].length || offset >end ){
			return;
		}
		setBitHelper(offset/2,end/2,lvl-1);

	}


	public static void main(String[] args){
		BuddySystem buddySystem = new BuddySystem();
		//set Bit test
		buddySystem.setBit(0,2);
		buddySystem.print();
		buddySystem.renew();
		buddySystem.setBit(0,3);
		buddySystem.print();
		buddySystem.renew();
		buddySystem.setBit(1,2);
		buddySystem.print();
		buddySystem.renew();
		buddySystem.setBit(1,3);
		buddySystem.print();
		buddySystem.renew();
		buddySystem.setBit(1,3);
		buddySystem.setBit(4,3);
		buddySystem.print();		

		//clear Bit test
		long timeStart = System.currentTimeMillis();
		
		// buddySystem.clearBit2(3,4);
		// buddySystem.print();
		// buddySystem.renew();
		// buddySystem.clearBit2(3,3);
		// buddySystem.print();
		// buddySystem.renew();
		// buddySystem.clearBit2(2,3);
		// buddySystem.print();
		// buddySystem.renew();
		// buddySystem.clearBit2(2,6);
		// buddySystem.print();
		// buddySystem.renew();
		// buddySystem.clearBit2(3,2);
		// buddySystem.print();
		// buddySystem.clearBit2(2,4);
		// buddySystem.print();
		// buddySystem.clearBit2(2,2);
		// buddySystem.print();
		// System.out.println("Time "+(System.currentTimeMillis()-timeStart));

		// buddySystem.renew();

		// timeStart = System.currentTimeMillis();
		// buddySystem.clearBit(3,4);
		// buddySystem.print();
		// buddySystem.renew();
		// buddySystem.clearBit(3,3);
		// buddySystem.print();
		// buddySystem.renew();
		// buddySystem.clearBit(2,3);
		// buddySystem.print();
		// buddySystem.renew();
		// buddySystem.clearBit(2,6);
		// buddySystem.print();
		// buddySystem.renew();
		// buddySystem.clearBit(3,2);
		// buddySystem.print();
		// buddySystem.clearBit(2,4);
		// buddySystem.print();
		// buddySystem.clearBit(2,2);
		// buddySystem.print();
		// System.out.println("Time "+(System.currentTimeMillis()-timeStart));


		//test set bit
	}
}