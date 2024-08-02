/*
 * Last changed at upstream commit 929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * https://github.com/espressif/esp32c3-bt-lib/commit/929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * Upstream date: 2024-08-02 17:03:33 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b445b5f)
 * Source: libbtdm_app -> lld.o -> lld_le_pkt_err_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_le_pkt_err_get(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = llm_hdl_to_id();
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar3 = 1;
  if (uVar1 < *(byte *)(iVar2 + 0xd)) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = CONCAT22(*(undefined2 *)(&lld_le_pkt_env + uVar1),
                          *(undefined2 *)((int)&lld_le_pkt_env + uVar1 * 4 + 2));
    }
    uVar3 = 0;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
  }
  return uVar3;
}

