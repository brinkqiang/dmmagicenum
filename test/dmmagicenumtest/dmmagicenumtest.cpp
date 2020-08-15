
#include "dmmagicenum.h"

int main( int argc, char* argv[] ) {

    Idmmagicenum* module = dmmagicenumGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
    return 0;
}
