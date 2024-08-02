/*
 * Last changed at upstream commit 929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * https://github.com/espressif/esp32c3-bt-lib/commit/929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * Upstream date: 2024-08-02 17:03:33 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b445b5f)
 * Source: libbtdm_app -> lld.o -> lld_le_pkt_err_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool lld_le_pkt_err_clear(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = llm_hdl_to_id();
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  bVar1 = *(byte *)(iVar3 + 0xd) <= uVar2;
  if (!bVar1) {
    (&lld_le_pkt_env)[uVar2] = 0;
  }
  return bVar1;
}

