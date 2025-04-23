/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> aes_k1.o -> r_aes_k1_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_aes_k1_continue(int param_1,void *param_2)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x340))(*(code **)(_r_modules_funcs_p + 0x340));
  if (iVar1 != 0) {
    if (*(char *)(param_1 + 0x39) == '\0') {
      return iVar1;
    }
    pvVar2 = memcpy((void *)(param_1 + 0x3a),param_2,0x10);
    iVar1 = _r_modules_funcs_p;
    *(undefined1 *)(param_1 + 0x39) = 0;
    (**(code **)(iVar1 + 0x344))
              (param_1,pvVar2,*(undefined4 *)(param_1 + 0x34),*(undefined1 *)(param_1 + 0x38),
               *(code **)(iVar1 + 0x344));
  }
  return 0;
}

