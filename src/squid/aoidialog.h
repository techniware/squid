/**
 * Copyright (c) 2010-2012 Thomas Schaffter (thomas.schaff...@gmail.com)
 *
 * We release this software open source under a Creative Commons Attribution-
 * NonCommercial 3.0 Unported License. Please cite the papers listed on
 * http://tschaffter.ch/projects/squid/ when using sQuid in your publication.
 *
 * For commercial use, please contact Thomas Schaffter.
 *
 * A brief description of the license is available at:
 * http://creativecommons.org/licenses/by-nc/3.0/
 *
 * The full license is available at:
 * http://creativecommons.org/licenses/by-nc/3.0/legalcode
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef AOIDIALOG_H
#define AOIDIALOG_H

#include "dc1394camera.h"
#include "dc1394utility.h"
#include "myexception.h"
#include <QtGui/QDialog>

//! Elements of the graphical interface.
namespace Ui {
    class AoiDialog;
}
//! Graphical interface of sQuid.
namespace qsquid {

/**
 * \brief Implements a dialog to define the area of interest (AOI).
 *
 * @version February 28, 2012
 * @author Thomas Schaffter (thomas.schaff...@gmail.com)
 */
class AoiDialog : public QDialog {

    Q_OBJECT

private:

    /** Reference of the interface. */
    Ui::AoiDialog* ui_;
    /** Information about the video mode format7 of the selected camera. */
    dc1394format7mode_t* info_;

public:

    /** Constructor. */
    AoiDialog(QWidget* parent = 0);
    /** Destructor. */
    ~AoiDialog();

public slots:

    /** Called when a different camera is selected. */
    void changeCamera(int cameraIndex);
    /** Saves but doesn't apply the defined AOI to the selected camera. */
    bool apply();
    /** As apply() but applies the changes to the selected camera. */
    void accept();

private:

    /** Initialization. */
    void initialize() throw(MyException*);
    /** Updates the window when a different camera is selected. */
    void update(squid::Dc1394Camera* camera) throw(MyException*);
};

}

#endif // AOIDIALOG_H
