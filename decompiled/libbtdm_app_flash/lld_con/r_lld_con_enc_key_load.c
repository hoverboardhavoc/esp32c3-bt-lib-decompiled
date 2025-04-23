/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_enc_key_load
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_enc_key_load(int param_1,int param_2,undefined2 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  if (*(int *)(&lld_con_env + param_1 * 4) != 0) {
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    param_1 = param_1 * 0x5a;
    iVar6 = 0;
    *(undefined2 *)(param_1 + 0x44 + iVar4) = 0;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(param_1 + 0x46 + iVar4) = 0;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(param_1 + 0x48 + iVar4) = 0;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(param_1 + 0x4a + iVar4) = 0;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(param_1 + 0x4c + iVar4) = 0;
    iVar4 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(param_1 + 0x4e + iVar4) = 0;
    do {
      uVar3 = *param_3;
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar4 + param_1 + 0x3c + iVar6) = uVar3;
      iVar6 = iVar6 + 2;
      param_3 = param_3 + 1;
    } while (iVar6 != 8);
    iVar4 = 0;
    do {
      puVar5 = (undefined1 *)((0xfU - iVar4 & 0xff) + param_2);
      uVar1 = puVar5[-1];
      uVar2 = *puVar5;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + param_1 + 0x2c + iVar4) = CONCAT11(uVar1,uVar2);
      iVar4 = iVar4 + 2;
    } while (iVar4 != 0x10);
    return;
  }
  return;
}

