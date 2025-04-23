/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_set_tx_power
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_set_tx_power(int param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  
  uVar3 = (*_r_llm_plan_elt_get)(param_2,param_1,_r_llm_plan_elt_get);
  iVar4 = r_emi_get_mem_addr_by_offset(0x400);
  iVar2 = param_1 * 0x5a + 0x18;
  uVar1 = *(ushort *)(iVar4 + iVar2);
  iVar4 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar4 + iVar2) = uVar3 | uVar1 & 0xff00;
  return;
}

