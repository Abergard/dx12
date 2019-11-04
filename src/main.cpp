#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include <shellapi.h>

#if defined(min)
#undef min
#endif

#if defined(max)
#undef max
#endif

#if defined(CreateWindow)
#undef CreateWindow
#endif

// Windows Runtime Library. Needed for Microsoft::WRL::ComPtr<> template class.
#include <wrl.h>

// DirectX 12 specific headers.
#include <DirectXMath.h>
#include <d3d12.h>
#include <d3dcompiler.h>
#include <dxgi1_6.h>

// D3D12 extension library.
#include <d3dx12.h>

// STL
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>

#include "helpers.h"

using namespace Microsoft::WRL;

const std::uint8_t number_of_frames{3};
bool use_warp{false};

std::uint32_t client_width{1280};
std::uint32_t client_height{720};

bool is_initialized{false};

HWND hwnd{};
RECT window_rect{};

ComPtr<ID3D12Device2> device{};
ComPtr<ID3D12CommandQueue> command_queue{};
ComPtr<IDXGISwapChain4> swap_chain{};
ComPtr<ID3D12Resource> back_buffers[number_of_frames]{};
ComPtr<ID3D12GraphicsCommandList> command_list{};
ComPtr<ID3D12CommandAllocator> command_allocators[number_of_frames]{};
ComPtr<ID3D12DescriptorHeap> rtv_descriptor_heap{};

std::size_t rtv_descriptor_size{};
std::size_t current_back_buffer_index{};

ComPtr<ID3D12Fence> fence;
std::uint64_t fence_value{0};
std::uint64_t frame_fence_values[number_of_frames]{};
HANDLE fence_event;

bool vsync{true};
bool tearing_supported{false};
bool fullscreen{false};

int main()
{
    std::clog << "hello world\n";
}
