/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc_con_upd.o -> ll_connection_param_req_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_connection_param_req_handler_pre(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (10 < *(ushort *)(param_2 + 2)) {
    return 0;
  }
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x7c8))(*(code **)(_r_ip_funcs_p + 0x7c8));
  uVar3 = 0x23;
  if ((uVar2 < 2) && (uVar3 = 0x23, *(char *)(iVar1 + 0x1c) != '\x03')) {
    if (*(char *)(iVar1 + 0x1d) == '\x03') {
      uVar3 = 0x23;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

