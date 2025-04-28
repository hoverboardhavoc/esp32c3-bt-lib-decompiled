/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  byte bVar3;
  ushort uVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  
  cVar5 = rwip_priority;
  if (param_1 == 0) {
    uVar7 = 0x9de;
_L24:
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
      goto _L24;
    }
    bVar1 = *(byte *)(param_1 + 0x53);
    bVar2 = *(byte *)(param_1 + 0x5d);
    bVar3 = *(byte *)(param_1 + 0x46);
    uVar4 = *(ushort *)(_p_lld_env + 0xd4);
    if ((bVar2 & 0xc0) != 0) {
      r_assert_err(0,0x10000,0x2b0);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar8 = ((uint)bVar1 * 9 & 0xff) * 0xe;
    *(ushort *)(iVar8 + 8 + iVar6) =
         (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar2 | (ushort)bVar3 << 8;
    uVar9 = (uint)*(byte *)(param_1 + 0x5c) << 5;
    uVar4 = *(ushort *)(param_1 + 0x46) >> 8;
    if ((uVar9 & 0xffffff1f) != 0) {
      r_assert_err(0,0x10000,0x31c);
    }
    if ((uVar4 & 0xffe0) != 0) {
      r_assert_err(0,0x10000,0x31d);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar7 = *(undefined4 *)(param_1 + 0x10);
    *(ushort *)(iVar8 + 10 + iVar6) = uVar4 | (ushort)uVar9;
    *(undefined1 *)(param_1 + 0x61) = 0;
    *(undefined4 *)(param_1 + -0x24) = uVar7;
  }
  return;
}

