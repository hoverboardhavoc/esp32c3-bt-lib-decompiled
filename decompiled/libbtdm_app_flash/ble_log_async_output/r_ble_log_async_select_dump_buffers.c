/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> r_ble_log_async_select_dump_buffers
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_async_select_dump_buffers(uint param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = _ble_log_async_env;
  piVar4 = *(int **)(_ble_log_async_env + 0xc);
  *(byte *)(*piVar4 + 0x18) = *(byte *)(*piVar4 + 0x18) & 0xfe;
  *(byte *)(piVar4[1] + 0x18) = *(byte *)(piVar4[1] + 0x18) & 0xfe;
  iVar1 = *(int *)(iVar1 + 0xc);
  *(byte *)(piVar4[2] + 0x18) = *(byte *)(piVar4[2] + 0x18) & 0xfe;
  iVar5 = 0;
  do {
    if (param_1 == 0) {
      return;
    }
    iVar3 = *(int *)(iVar1 + iVar5);
    if (((param_1 & 1) == 0) ||
       (bVar2 = *(byte *)(iVar3 + 0x18) | 1, (*(byte *)(iVar3 + 0x18) & 2) == 0)) {
      bVar2 = *(byte *)(iVar3 + 0x18) & 0xfe;
    }
    *(byte *)(iVar3 + 0x18) = bVar2;
    iVar5 = iVar5 + 4;
    param_1 = param_1 >> 1;
  } while (iVar5 != 0xc);
  return;
}

