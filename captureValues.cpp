#include <iostream>
#include <alerror/alerror.h>
#include <alcommon/alproxy.h>

using namespace std;

int main(int argc, char* argv[]) {
  if(argc != 3)
  {
    std::cerr << "Wrong number of arguments!" << std::endl;
    std::cerr << "Usage: captureValues NAO_IP fileName" << std::endl;
    exit(2);
  }

  const std::string robotIP = argv[1];
  int port = 9559;

  try {
    /** Create a generic proxy to "HelloWorld" module.
    * Arguments for the constructor are
    * - name of the module
    * - string containing the IP adress of the robot
    * - port (default is 9559)
    */
    boost::shared_ptr<AL::ALProxy> testProxy
    = boost::shared_ptr<AL::ALProxy>(new AL::ALProxy("GetValoresCorriente", robotIP, port));

    const std::string fileName = argv[2];
    testProxy->callVoid("startAcquiring",fileName);

    cout << "Capturando\n";
    cout << "Presione una tecla para terminar la captura\n";
    cin.get();

    testProxy->callVoid("stopAcquiring");
  }
  catch (const AL::ALError& e) {
    std::cerr << e.what() << std::endl;
  }
}
