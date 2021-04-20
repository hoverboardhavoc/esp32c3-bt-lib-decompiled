/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llc_con_upd.o -> ll_connection_param_req_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_connection_param_req_handler_pre(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (10 < *(ushort *)(param_2 + 2)) {
    return 0;
  }
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  uVar2 = lld_con_count_get();
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

