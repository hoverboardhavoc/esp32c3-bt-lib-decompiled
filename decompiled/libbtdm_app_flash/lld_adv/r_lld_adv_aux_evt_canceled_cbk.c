/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_aux_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_aux_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  cVar5 = rwip_priority;
  if (param_1 == 0) {
    uVar7 = 0x9de;
_L18:
    r_assert_err(0,0x10000,uVar7);
    return;
  }
  if ((uint)(*(int *)(param_1 + 0x30) << 1) <=
      (*(int *)(param_1 + 4) - *(int *)(param_1 + 0x2c) & 0xfffffffU)) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 4);
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar5;
  }
  iVar6 = r_sch_arb_insert(param_1);
  if (iVar6 != 0) {
    if (*(int *)(param_1 + 0x24) == -1) {
      uVar7 = 0x9d8;
      goto _L18;
    }
    bVar1 = *(byte *)(param_1 + 0x53);
    bVar2 = *(byte *)(param_1 + 0x5d);
    sVar3 = *(short *)(param_1 + 0x46);
    uVar4 = *(ushort *)(_p_lld_env + 0xd4);
    if (0x3f < bVar2) {
      r_assert_err(0,0x10000,0x2b0);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar8 = ((uint)bVar1 * 9 & 0xff) * 0xe;
    *(ushort *)(iVar8 + 8 + iVar6) = (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar2 | sVar3 << 8;
    bVar1 = *(byte *)(param_1 + 0x5c);
    uVar4 = *(ushort *)(param_1 + 0x46) >> 8;
    if ((bVar1 & 0xf8) != 0) {
      r_assert_err(0,0x10000,0x31c);
    }
    if (0x1f < uVar4) {
      r_assert_err(0,0x10000,0x31d);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar7 = *(undefined4 *)(param_1 + 0x10);
    *(ushort *)(iVar8 + 10 + iVar6) = uVar4 | (ushort)bVar1 << 5;
    *(undefined1 *)(param_1 + 0x61) = 0;
    *(undefined4 *)(param_1 + -0x24) = uVar7;
  }
  return;
}

