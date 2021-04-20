/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rf_txpwr.o -> ble_txpwr_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ble_txpwr_set(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  if (param_1 < 0xc) {
    uVar1 = 0xfffffffe;
    if (param_2 < 0x10) {
      if ((_r_plf_funcs_p == 0) ||
         (iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(0xfffffffe,*(code **)(_r_plf_funcs_p + 0x38))
         , (*(byte *)(iVar2 + 0xc) & 1) == 0)) {
        uVar1 = 0xfffffffd;
      }
      else {
        uStack_14 = (undefined1)param_1;
        uStack_13 = (undefined1)param_2;
        uVar1 = (**(code **)(_r_plf_funcs_p + 0x28))
                          (0xb,&uStack_14,2,1,*(code **)(_r_plf_funcs_p + 0x28));
      }
    }
    return uVar1;
  }
  return 0xffffffff;
}

