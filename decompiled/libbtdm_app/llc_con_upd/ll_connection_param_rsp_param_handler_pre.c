/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llc_con_upd.o -> ll_connection_param_rsp_param_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_connection_param_rsp_param_handler_pre(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar1 == 5) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,0,*(code **)(_r_ip_funcs_p + 0x674));
    *(undefined2 *)(iVar1 + 0x14) = *(undefined2 *)(param_2 + 0xc);
    *(undefined2 *)(iVar1 + 0x16) = *(undefined2 *)(param_2 + 0xe);
  }
  return 0;
}

