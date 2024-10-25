/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_ver_exch.o -> r_llc_hci_version_info_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_hci_version_info_send(undefined4 param_1,int param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1103,param_1,0xc,10);
  *(short *)(puVar1 + 2) = (short)param_1;
  *puVar1 = (char)param_2;
  if (param_2 == 0) {
    *(undefined2 *)(puVar1 + 6) = *(undefined2 *)(param_3 + 2);
    *(undefined2 *)(puVar1 + 8) = *(undefined2 *)(param_3 + 4);
    puVar1[4] = *param_3;
  }
  r_hci_send_2_host();
  return;
}

