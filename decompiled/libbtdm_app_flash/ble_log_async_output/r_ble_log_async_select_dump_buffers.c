/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> r_ble_log_async_select_dump_buffers
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_async_select_dump_buffers(uint param_1)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  
  piVar4 = *(int **)(_ble_log_async_env + 0xc);
  piVar1 = piVar4 + 3;
  *(byte *)(*piVar4 + 0x18) = *(byte *)(*piVar4 + 0x18) & 0xfe;
  *(byte *)(piVar4[1] + 0x18) = *(byte *)(piVar4[1] + 0x18) & 0xfe;
  *(byte *)(piVar4[2] + 0x18) = *(byte *)(piVar4[2] + 0x18) & 0xfe;
  do {
    if (param_1 == 0) {
      return;
    }
    iVar2 = *piVar4;
    bVar3 = 0;
    if ((param_1 & 1) != 0) {
      bVar3 = (byte)(*(uint *)(iVar2 + 0x18) >> 1) & 1;
    }
    piVar4 = piVar4 + 1;
    param_1 = param_1 >> 1;
    *(byte *)(iVar2 + 0x18) = bVar3 | *(byte *)(iVar2 + 0x18) & 0xfe;
  } while (piVar4 != piVar1);
  return;
}

