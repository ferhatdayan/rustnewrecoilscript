#include "ImGui/ImGui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"
#include <d3d9.h>
#include <tchar.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <random>
#include <thread>
#include <vector>
struct Vector1
{
	double x;
	double y;
};
std::vector<Vector1> CoorAK = { {0.000000,-2.257792},{0.323242,-2.300758},{0.649593,-2.299759},{0.848786,-2.259034},{1.075408,-2.323947},{1.268491,-2.215956},{1.330963,-2.236556},{1.336833,-2.218203},{1.505516,-2.143454},{1.504423,-2.233091},{1.442116,-2.270194},{1.478543,-2.204318},{1.392874,-2.165817},{1.480824,-2.177887},{1.597069,-2.270915},{1.449996,-2.145893},{1.369179,-2.270450},{1.582363,-2.298334},{1.516872,-2.235066},{1.498249,-2.238401},{1.465769,-2.331642},{1.564812,-2.242621},{1.517519,-2.303052},{1.422433,-2.211946},{1.553195,-2.248043},{1.510463,-2.285327},{1.553878,-2.240047},{1.520380,-2.221839},{1.553878,-2.240047},{1.553195,-2.248043} };
std::vector<Vector1> CoorLR = { {0.000000,-2.052616},{0.055584,-1.897695},{-0.247226,-1.863222},{-0.243871,-1.940010},{0.095727,-1.966751},{0.107707,-1.885520},{0.324888,-1.946722},{-0.181137,-1.880342},{0.162399,-1.820107},{-0.292076,-1.994940},{0.064575,-1.837156},{-0.126699,-1.887880},{-0.090568,-1.832799},{0.065338,-1.807480},{-0.197343,-1.705888},{-0.216561,-1.785949},{0.042567,-1.806371},{-0.065534,-1.757623},{0.086380,-1.904010},{-0.097326,-1.969296},{-0.213034,-1.850288},{-0.017790,-1.730867},{-0.045577,-1.783686},{-0.053309,-1.886260},{0.055072,-1.793076},{-0.091874,-1.921906},{-0.033719,-1.796160},{0.266464,-1.993952},{0.079090,-1.921165} };
std::vector<Vector1> CoorMP5 = { {0.125361,-1.052446},{-0.099548,-0.931548},{0.027825,-0.954094},{-0.013715,-0.851504},{-0.007947,-1.070579},{0.096096,-1.018017},{-0.045937,-0.794216},{0.034316,-1.112618},{-0.003968,-0.930040},{-0.009403,-0.888503},{0.140813,-0.970807},{-0.015052,-1.046551},{0.095699,-0.860475},{-0.269643,-1.038896},{0.000285,-0.840478},{0.018413,-1.038126},{0.099191,-0.851701},{0.199659,-0.893041},{-0.082660,-1.069278},{0.006826,-0.881493},{0.091709,-1.150956},{-0.108677,-0.965513},{0.169612,-1.099499},{-0.038244,-1.120084},{-0.085513,-0.876956},{0.136279,-1.047589},{0.196392,-1.039977},{-0.152513,-1.209291},{-0.214510,-0.956648},{0.034276,-0.095177} };
std::vector<Vector1> CoorSMG = { {-0.114414,-0.680635},{0.008685,-0.676597},{0.010312,-0.682837},{0.064825,-0.691344},{0.104075,-0.655617},{-0.088118,-0.660429},{0.089906,-0.675183},{0.037071,-0.632623},{0.178466,-0.634737},{0.034653,-0.669444},{-0.082658,-0.664827},{0.025551,-0.636631},{0.082413,-0.647118},{-0.123305,-0.662104},{0.028164,-0.662354},{-0.117345,-0.693474},{-0.268777,-0.661122},{-0.053086,-0.677493},{0.004238,-0.647037},{0.014169,-0.551440},{-0.009907,-0.552079},{0.044076,-0.577694},{-0.043187,-0.549581} };
std::vector<Vector1> CoorTHOMP = { {-0.114413,-0.680635},{0.008686,-0.676598},{0.010312,-0.682837},{0.064825,-0.691345},{0.104075,-0.655618},{-0.088118,-0.660429},{0.089906,-0.675183},{0.037071,-0.632623},{0.178465,-0.634737},{0.034654,-0.669443},{-0.082658,-0.664826},{0.025550,-0.636631},{0.082414,-0.647118},{-0.123305,-0.662104},{0.028164,-0.662354},{-0.117346,-0.693475},{-0.268777,-0.661123},{-0.053086,-0.677493},{0.004238,-0.647038} };
std::vector<double> MTimeAK = { 121.96149709966872,92.6333814724611,138.60598637206294,113.37874368443146,66.25151186427745,66.29530438019354,75.9327831420658,85.05526144256157,
89.20256669256554,86.68010184667988,78.82145888317788,70.0451048111144,60.85979604582978,59.51642457624619,71.66762996283607,86.74060009403034,98.3363599080854,104.34161954944257,
104.09299204005345,97.58780746901739,85.48062700875559,70.4889202349561,56.56417811530545,47.386907899993936,56.63787408680247,91.5937793023631,112.38667610336424,111.39338971888095,
87.5067801164596 };
namespace WeaponBase {
	struct {
		const double WaitTime = 133.3333;
	}WTAK;
	struct {
		const int WaitTime = 118;
	}WTLR;
	struct {
		const int WaitTime = 98;
	}WTMP5;
	struct {
		const int WaitTime = 99;
	}WTSMG;
	struct {
		const int WaitTime = 127;
	}WTTHOMP;
}
namespace ModData {
	struct {
		double Scope8X = 4.76;
		double ScopeHOLO = 1.2;
		double ScopeHAND = 0.8;
		double ScopeNONE = 1.0;
	}Scope;
	struct {
		double BarrelSILEN = 0.8;
		double BarrelNONE = 1.0;
	}Barrel;
}

bool WPAK, WPLR, WPMP5, WPSMG, WPTHOMP, Mod8X, ModHOLO, ModHAND, ModSILEN;
float Sensitivity = 1; int FOV = 90;
std::string wptext = ("-"), scptext = "-", brltext = "-";


void SleepTime(int wt)
{
	LONGLONG atime;
	LONGLONG itime;
	LONGLONG mtime;
	QueryPerformanceFrequency((LARGE_INTEGER*)&atime);
	atime /= 1000;
	QueryPerformanceCounter((LARGE_INTEGER*)&mtime);
	itime = mtime / atime + wt;
	mtime = 0;
	while (mtime < itime)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&mtime);
		mtime /= atime;
	}
}
void SlowRec(double wt, double ct, int x1, int y1) {
	int x_ = 0, y_ = 0, t_ = 0;
	for (int i = 1; i <= (int)ct; ++i) {
		int xI = i * x1 / (int)ct;
		int yI = i * y1 / (int)ct;
		int tI = i * (int)ct / (int)ct;
		mouse_event(1, (int)xI - (int)x_, (int)yI - (int)y_, 0, 0);
		SleepTime((int)tI - (int)t_);
		x_ = xI; y_ = yI; t_ = tI;
	}
	SleepTime((int)wt - (int)ct);
}
int checkboost(float Delay) {
	return (int)Delay;
}
double BarrelData() {
	if (ModSILEN == true) {
		if (WPSMG == true)
			ModData::Barrel.BarrelSILEN = 0.85;
		if (ModHAND == true || ModHOLO == true)
			return 0.75;
		if (Mod8X == true && ModSILEN == true)
			return 1.46;
		else
			return ModData::Barrel.BarrelSILEN;
	}
	else
		return ModData::Barrel.BarrelNONE;
}
double ScopeData() {
	if (Mod8X == true) {
		if (WPSMG == true || WPTHOMP == true) {
			if (Mod8X == true)
				return ModData::Scope.Scope8X + 0.75;
		}
		return ModData::Scope.Scope8X;
	}
	else if (ModHAND == true) {
		if (WPSMG == true || WPTHOMP == true) {
			if (ModHAND == true)
				return ModData::Scope.ScopeHAND + 0.1;
		}
		return ModData::Scope.ScopeHAND;
	}
	else if (ModHOLO == true) {
		if (WPSMG == true || WPTHOMP == true) {
			if (ModHOLO == true)
				return ModData::Scope.ScopeHOLO + 0.3;
		}
		return ModData::Scope.ScopeHOLO;
	}
	else
		return ModData::Scope.ScopeNONE;
}
namespace NowWP {
	double x(int mermi) {
		if (GetAsyncKeyState(VK_CONTROL)) {
			if (WPAK == true)
				return (((CoorAK[mermi].x * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity * 2) * 3.0 * (FOV / 100.0))));
			else if (WPLR == true)
				return (((CoorLR[mermi].x * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity * 2) * 3.0 * (FOV / 100.0))));
			else if (WPMP5 == true)
				return (((CoorMP5[mermi].x * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity * 2) * 3.0 * (FOV / 100.0))));
			else if (WPTHOMP == true)
				return (((CoorTHOMP[mermi].x * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity * 2) * 3.0 * (FOV / 100.0))));
			else if (WPSMG == true)
				return (((CoorSMG[mermi].x * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity * 2) * 3.0 * (FOV / 100.0))));
			else
				return 0;
		}
		else
		{
			if (WPAK == true)
				return (((CoorAK[mermi].x * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity) * 3.0 * (FOV / 100.0))));
			else if (WPLR == true)
				return (((CoorLR[mermi].x * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity) * 3.0 * (FOV / 100.0))));
			else if (WPMP5 == true)
				return (((CoorMP5[mermi].x * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity) * 3.0 * (FOV / 100.0))));
			else if (WPTHOMP == true)
				return (((CoorTHOMP[mermi].x * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity) * 3.0 * (FOV / 100.0))));
			else if (WPSMG == true)
				return (((CoorSMG[mermi].x * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity) * 3.0 * (FOV / 100.0))));
			else
				return 0;
		}
	}
	double y(int mermi) {
		if (GetAsyncKeyState(VK_CONTROL)) {
			if (WPAK == true)
				return (((CoorAK[mermi].y * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity * 2) * 3.0 * (FOV / 100.0))));
			else if (WPLR == true)
				return (((CoorLR[mermi].y * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity * 2) * 3.0 * (FOV / 100.0))));
			else if (WPMP5 == true)
				return (((CoorMP5[mermi].y * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity * 2) * 3.0 * (FOV / 100.0))));
			else if (WPTHOMP == true)
				return (((CoorTHOMP[mermi].y * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity * 2) * 3.0 * (FOV / 100.0))));
			else if (WPSMG == true)
				return (((CoorSMG[mermi].y * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity * 2) * 3.0 * (FOV / 100.0))));
			else
				return 0;
		}
		else
		{
			if (WPAK == true)
				return (((CoorAK[mermi].y * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity) * 3.0 * (FOV / 100.0))));
			else if (WPLR == true)
				return (((CoorLR[mermi].y * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity) * 3.0 * (FOV / 100.0))));
			else if (WPMP5 == true)
				return (((CoorMP5[mermi].y * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity) * 3.0 * (FOV / 100.0))));
			else if (WPTHOMP == true)
				return (((CoorTHOMP[mermi].y * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity) * 3.0 * (FOV / 100.0))));
			else if (WPSMG == true)
				return (((CoorSMG[mermi].y * ScopeData()) * BarrelData() / (-0.03 * (Sensitivity) * 3.0 * (FOV / 100.0))));
			else
				return 0;
		}
	}
	double Delaying() {
		if (WPAK == true)
			return WeaponBase::WTAK.WaitTime;
		else if (WPLR == true)
			return WeaponBase::WTLR.WaitTime;
		else if (WPMP5 == true)
			return WeaponBase::WTMP5.WaitTime;
		else if (WPTHOMP == true)
			return WeaponBase::WTTHOMP.WaitTime;
		else if (WPSMG == true)
			return WeaponBase::WTSMG.WaitTime;
		else
			return 0;
	}
	double DelayingMulti(int mermi) {
		if (WPAK == true)
			return MTimeAK[mermi];
		else if (WPLR == true)
			return WeaponBase::WTLR.WaitTime;
		else if (WPMP5 == true)
			return WeaponBase::WTMP5.WaitTime;
		else if (WPTHOMP == true)
			return WeaponBase::WTTHOMP.WaitTime;
		else if (WPSMG == true)
			return WeaponBase::WTSMG.WaitTime;
		else
			return 0;
	}
	int BulletCheck() {
		if (WPAK == true)
			return CoorAK.size() - 1;
		else if (WPLR == true)
			return CoorLR.size() - 1;
		else if (WPMP5 == true)
			return CoorMP5.size() - 1;
		else if (WPTHOMP == true)
			return CoorTHOMP.size() - 1;
		else if (WPSMG == true)
			return CoorSMG.size() - 1;
		else
			return 0;
	}
	bool WPCheck() {
		if (WPAK == true || WPLR == true || WPMP5 == true || WPTHOMP == true || WPSMG == true)
			return true;
		else
			return false;
	}
};
bool MainFunc() {
	for (;;) {
		if (NowWP::WPCheck() == true)
		{
			for (int i = 0; i <= NowWP::BulletCheck() && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000; i++)
			{
				SlowRec((int)checkboost((float)NowWP::Delaying()), (int)checkboost(NowWP::DelayingMulti(i)), (int)NowWP::x(i), (int)NowWP::y(i));
			}
			Sleep(1);
		}
		Sleep(1);
	}
	return false;
}

static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int main()
{
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainFunc, 0, 0, 0);
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T(("Main")), NULL };
	::RegisterClassEx(&wc);
	HWND hwnd = ::CreateWindow(wc.lpszClassName, _T(("Main")), WS_OVERLAPPEDWINDOW, 0, 0, 50, 50, NULL, NULL, wc.hInstance, NULL);
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	if (!CreateDeviceD3D(hwnd))
	{
		CleanupDeviceD3D();
		::UnregisterClass(wc.lpszClassName, wc.hInstance);
		return 1;
	}
	::ShowWindow(hwnd, SW_HIDE);
	::UpdateWindow(hwnd);
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	ImGui::StyleColorsDark();
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX9_Init(g_pd3dDevice);
	bool done = false;
	while (!done)
	{
		MSG msg;
		while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
				done = true;
		}
		if (done)
			break;
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		{
			ImGui::Begin(("Main"));
			{
				ImGui::BeginGroup();
				ImGui::Text(("Sensitivity"));
				ImGui::SliderFloat(("##Sensitivity"), &Sensitivity, 0.001, 1, ("%.2f"));
				ImGui::Text(("FOV"));
				ImGui::SliderInt(("##FOV"), &FOV, 65, 90);
				ImGui::EndGroup();
				ImGui::BeginGroup();
				if (ImGui::Button((" AK"), ImVec2(100, 20))) {
					WPAK = true; WPLR = false; WPMP5 = false; WPSMG = false; WPTHOMP = false; wptext = ("ak");
				}
				if (ImGui::Button((" LR"), ImVec2(100, 20))) {
					WPAK = false; WPLR = true; WPMP5 = false; WPSMG = false; WPTHOMP = false; wptext = ("lr");
				}
				if (ImGui::Button((" MP5"), ImVec2(100, 20))) {
					WPAK = false; WPLR = false; WPMP5 = true; WPSMG = false; WPTHOMP = false; wptext = ("mp5");
				}
				if (ImGui::Button((" SMG"), ImVec2(100, 20))) {
					WPAK = false; WPLR = false; WPMP5 = false; WPSMG = true; WPTHOMP = false; wptext = ("smg");
				}
				if (ImGui::Button((" THOMP"), ImVec2(100, 20))) {
					WPAK = false; WPLR = false; WPMP5 = false; WPSMG = false; WPTHOMP = true; wptext = ("thomp");
				}
				ImGui::EndGroup();
				ImGui::SameLine();
				ImGui::BeginGroup();
				if (ImGui::Button((" 8x"), ImVec2(100, 20))) {
					Mod8X = true; ModHOLO = false; ModHAND = false; scptext = ("8x");
				}
				if (ImGui::Button((" Hand"), ImVec2(100, 20))) {
					ModHAND = true; Mod8X = false; ModHOLO = false; scptext = ("hand");
				}
				if (ImGui::Button((" Holo"), ImVec2(100, 20))) {
					ModHOLO = true; Mod8X = false; ModHAND = false; scptext = ("holo");
				}
				if (ImGui::Button((" Silen"), ImVec2(100, 20))) {
					ModSILEN = true; brltext = ("sus");
				}
				if (ImGui::Button((" MOD reset"), ImVec2(100, 20))) {
					ModSILEN = false; ModHOLO = false; ModHAND = false; Mod8X = false; brltext = ("-"); scptext = ("-");
				}
				ImGui::EndGroup();
				if (ImGui::Button((" reset"), ImVec2(100, 20))) {
					ModSILEN = false; ModHOLO = false; ModHAND = false; Mod8X = false; brltext = ("-"); scptext = ("-"); wptext = ("-");
					WPLR = false; WPMP5 = false; WPTHOMP = false;   WPAK = false; WPSMG = false;
				}
				ImGui::SameLine();
				if (ImGui::Button(("exit"), ImVec2(100, 20))) {
					exit(0);
				}
				ImGui::Text(wptext.c_str());
				ImGui::SameLine();
				ImGui::Text(scptext.c_str());
				ImGui::SameLine();
				ImGui::Text(brltext.c_str());
			}
			ImGui::End();
		}
		ImGui::EndFrame();
		g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
		g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
		g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, NULL, 1.0f, 0);
		if (g_pd3dDevice->BeginScene() >= 0)
		{
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			g_pd3dDevice->EndScene();
		}
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
		}
		HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
		if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
			ResetDevice();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	CleanupDeviceD3D();
	::DestroyWindow(hwnd);
	::UnregisterClass(wc.lpszClassName, wc.hInstance);
	return 0;
}
bool CreateDeviceD3D(HWND hWnd)
{
	if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return false;
	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
		return false;
	return true;
}
void CleanupDeviceD3D()
{
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
	if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}
void ResetDevice()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
	if (hr == D3DERR_INVALIDCALL)
		IM_ASSERT(0);
	ImGui_ImplDX9_CreateDeviceObjects();
}
#ifndef WM_DPICHANGED
#define WM_DPICHANGED 0x02E0
#endif
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;
	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			g_d3dpp.BackBufferWidth = LOWORD(lParam);
			g_d3dpp.BackBufferHeight = HIWORD(lParam);
			ResetDevice();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
			return 0;
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	case WM_DPICHANGED:
		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DpiEnableScaleViewports)
		{
			const RECT* suggested_rect = (RECT*)lParam;
			::SetWindowPos(hWnd, NULL, suggested_rect->left, suggested_rect->top, suggested_rect->right - suggested_rect->left, suggested_rect->bottom - suggested_rect->top, SWP_NOZORDER | SWP_NOACTIVATE);
		}
		break;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}