# ACCELERATED GRAPHICS (Pi1, 2, 3 - AARCH32, Pi3 AARCH64)
>
Code background: 
http://latchup.blogspot.com.au/2016/02/life-of-triangle.html
>
You will require this reference
https://docs.broadcom.com/docs/12358545
>
I currently have the C file called rpi-GLES.C really at the moment we are lower than that beating up the GL pipe inside the VC4 directly.
>
The first sample here passes in the raw active onscreen framebuffer. As we start to animate stuff I strongly suggest you don't do this as the render will produce screen tear. 
What I am going to do and I suggest you do the same is setup the virtual screen size to twice that of the screen. You render to the half the framebuffer that isn't visible.
You can control which half currently displayed by the mailbox Set virtual offset Tag: 0x00048009. So you should be flip-flopping between rendering and displaying the 
different halfs of the virtual screen the new render always going to the non displayed half.
>
As we get a bit further I will do more writeup. For now feel free to ask questions on the Raspberry forum
>https://www.raspberrypi.org/forums/viewtopic.php?f=72&p=1206923#p1206923

Also be aware there is a new Pi coming with a VC5. It is going to follow along the same path from what has been released.
>https://anholt.github.io/twivc4/2017/08/28/twiv/
>https://www.phoronix.com/scan.php?page=news_item&px=VC5-Broadcom-Gallium3D