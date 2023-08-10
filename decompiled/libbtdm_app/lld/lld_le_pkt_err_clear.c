/*
 * Last changed at upstream commit 0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * Upstream date: 2023-08-10 21:56:13 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(59725b5)
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

