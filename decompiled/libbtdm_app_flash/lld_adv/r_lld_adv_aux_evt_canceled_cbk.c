/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  cVar5 = rwip_priority;
  if (param_1 == 0) {
    uVar8 = 0x9ed;
_L24:
    r_assert_err(0,"lld_adv.c",uVar8);
    return;
  }
  if ((uint)(*(int *)(param_1 + 0x30) << 1) <=
      (*(int *)(param_1 + 4) - *(int *)(param_1 + 0x2c) & 0xfffffffU)) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 4);
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar5;
  }
  iVar7 = r_sch_arb_insert(param_1);
  if (iVar7 != 0) {
    if (*(int *)(param_1 + 0x24) == -1) {
      uVar8 = 0x9e7;
      goto _L24;
    }
    bVar1 = *(byte *)(param_1 + 0x53);
    bVar2 = *(byte *)(param_1 + 0x5d);
    bVar3 = *(byte *)(param_1 + 0x46);
    uVar4 = *(ushort *)(_p_lld_env + 0xd4);
    if ((bVar2 & 0xc0) != 0) {
      r_assert_err(0,"lld_adv.c",0x2b0);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar9 = ((uint)bVar1 * 9 & 0xff) * 0xe;
    *(ushort *)(iVar7 + iVar9 + 8) =
         (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar2 | (ushort)bVar3 << 8;
    uVar4 = *(ushort *)(param_1 + 0x46) >> 8;
    uVar6 = (uint)*(byte *)(param_1 + 0x5c) << 5;
    if ((uVar6 & 0xffffff1f) != 0) {
      r_assert_err(0,"lld_adv.c",0x31c);
    }
    if ((uVar4 & 0xffe0) != 0) {
      r_assert_err(0,"lld_adv.c",0x31d);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar8 = *(undefined4 *)(param_1 + 0x10);
    *(ushort *)(iVar9 + 10 + iVar7) = (ushort)uVar6 | uVar4;
    *(undefined1 *)(param_1 + 0x61) = 0;
    *(undefined4 *)(param_1 + -0x24) = uVar8;
  }
  return;
}

