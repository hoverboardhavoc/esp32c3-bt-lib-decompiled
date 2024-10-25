/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_msg.o -> r_hci_pack_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_hci_pack_bytes(int *param_1,int *param_2,uint param_3,uint param_4,size_t param_5)

{
  int iVar1;
  
  iVar1 = 1;
  if (*param_1 + param_5 <= param_3) {
    iVar1 = 0;
    if (param_4 != 0) {
      iVar1 = (uint)(param_4 < *param_2 + param_5) << 1;
      memcpy((void *)*param_2,(void *)*param_1,param_5);
    }
    *param_1 = *param_1 + param_5;
    *param_2 = param_5 + *param_2;
  }
  return iVar1;
}

