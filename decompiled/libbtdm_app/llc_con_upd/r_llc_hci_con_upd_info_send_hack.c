/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_hci_con_upd_info_send_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_hci_con_upd_info_send_hack(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  lld_con_update_last_clock();
  if (((param_3 != 0) && (param_2 == 0)) &&
     ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0)) {
    iVar1 = sdk_config_get_opts_ext();
    *(ushort *)(param_3 + 0x12) = (ushort)*(byte *)(iVar1 + 0x10);
    iVar1 = sdk_config_get_opts_ext();
    *(ushort *)(param_3 + 0x10) = (ushort)*(byte *)(iVar1 + 0x10);
  }
  r_llc_hci_con_upd_info_send(param_1,param_2,param_3);
  return;
}

