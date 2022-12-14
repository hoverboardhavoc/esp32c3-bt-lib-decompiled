/*
 * Last changed at upstream commit bba9af9259e0999ef246426d31a793fe0a3ff4db
 * https://github.com/espressif/esp32c3-bt-lib/commit/bba9af9259e0999ef246426d31a793fe0a3ff4db
 * Upstream date: 2022-12-14 15:32:37 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(80abacdd)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_evt_start_cbk_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_evt_start_cbk_hack(int param_1)

{
  byte bVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if (*(uint *)(param_1 + 0x24) == (uint)*(ushort *)(param_1 + 0x32)) {
      llm_update_duplicate_scan_count();
    }
  }
  if ((g_scan_forever != '\0') && (param_1 != 0)) {
    if (*(char *)(param_1 + 0x3c) != '\x02') {
      bVar1 = *(byte *)(param_1 + 0x38);
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      if (*(short *)(iVar2 + (uint)bVar1 * 0x5a + 0x20) != 1) {
        bVar1 = *(byte *)(param_1 + 0x38);
        iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar2 + (uint)bVar1 * 0x5a + 0x20) = 0;
        *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
      }
    }
  }
  r_lld_scan_evt_start_cbk(param_1);
  return;
}

