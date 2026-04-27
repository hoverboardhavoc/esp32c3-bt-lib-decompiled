/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_sched(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  
  iVar2 = *(int *)(_lld_init_env + param_1 * 4);
  iVar5 = r_lld_read_clock();
  bVar1 = *(byte *)(iVar2 + 0x52);
  uVar4 = (iVar5 - param_2 & 0xfffffffU) + 1 >> 1;
  if (*(char *)(iVar2 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar2 + 0x40);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0x44);
    *(uint *)(iVar2 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar2 + 0x4d) * 2) +
         *(int *)(iVar2 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar8 = DAT_00013042;
    if (DAT_00013042 < *(byte *)(iVar2 + 0x16)) {
      bVar8 = *(byte *)(iVar2 + 0x16);
    }
    *(byte *)(iVar2 + 0x16) = bVar8;
    *(ushort *)(iVar2 + 0x14) = DAT_00013043 & 0xf | 0x2000;
    iVar6 = r_sch_arb_insert(iVar2);
    if (iVar6 == 0) {
      uVar9 = (uint)*(byte *)(iVar2 + 0x4d);
      uVar4 = *(uint *)(iVar2 + 0x48);
      *(char *)(iVar2 + 0x3e) = (1 < uVar9) + '\x02';
      if ((uVar9 << 4 & 0xffffffcf) != 0) {
        r_assert_err(0x10000,0x1bf);
      }
      iVar6 = (uint)bVar1 * 0x5a;
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar5 + iVar6 + 4);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar6 + 4) = uVar3 & 0xffcf | (ushort)(uVar9 << 4);
      uVar3 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar9 * 2);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + 0x20 + iVar5) = (ushort)(((uint)uVar3 + uVar4 + 0x270) / 0x271) & 0xff;
      if (uVar4 < 0x4000) {
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        uVar3 = (ushort)(uVar4 + 1 >> 1);
      }
      else {
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        uVar3 = (ushort)((uVar4 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      *(ushort *)(iVar5 + iVar6 + 0x1a) = uVar3;
      uVar4 = (uint)*(byte *)(iVar2 + 0x4c) << 10;
      if ((uVar4 & 0x30000) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar5 + iVar6 + 0x26);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar6 + 0x26) = uVar3 & 0x3ff | (ushort)uVar4;
      goto _L84;
    }
    *(undefined1 *)(iVar2 + 0x3d) = 0;
  }
  if (uVar4 < *(uint *)(iVar2 + 0x24)) {
    uVar4 = *(uint *)(iVar2 + 0x24) - uVar4;
  }
  else {
    r_sch_slice_bg_remove(1);
    uVar4 = (uint)*(ushort *)(iVar2 + 0x2e);
    uVar9 = _sch_slice_params;
    if (_sch_slice_params == 0xffffffff) {
      uVar9 = (*(ushort *)(iVar2 + 0x2c) - uVar4) * 2 + iVar5 & 0xffffffc;
    }
    *(uint *)(iVar2 + 4) = uVar9;
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  uVar7 = (uint)_r_assert_param;
  *(uint *)(iVar2 + 0x24) = uVar4;
  uVar9 = uVar4 * 0x4e2;
  if (uVar7 < uVar4 * 0x4e2) {
    uVar9 = uVar7;
  }
  *(uint *)(iVar2 + 0x10) = uVar9;
  if (param_3 == 0) {
    *(undefined1 *)(iVar2 + 0x16) = DAT_00013046;
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar2 + 4);
  }
  iVar6 = (uint)bVar1 * 0x5a;
  *(ushort *)(iVar2 + 0x14) = DAT_00013047 & 0xf | 0x6000;
  *(undefined1 *)(iVar2 + 0x3e) = 1;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar6 + 0x20 + iVar5) = (short)uVar4;
  uVar4 = *(uint *)(iVar2 + 0x24);
  if ((uVar4 >> 0xf & 1) != 0) {
    r_assert_err(0,0x10000,0x4ab);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + 0x1a + iVar5) = (ushort)uVar4 | 0x8000;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x46 + iVar5) = 0;
  iVar5 = r_sch_arb_insert(iVar2);
  if (iVar5 != 0) {
    r_assert_err(0,0x10000,0x280);
    return;
  }
_L84:
  *(undefined1 *)(iVar2 + 0x50) = 0;
  return;
}

