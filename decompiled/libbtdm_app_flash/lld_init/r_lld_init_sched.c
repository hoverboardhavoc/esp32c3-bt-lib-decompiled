/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  
  iVar3 = *(int *)(_lld_init_env + param_1 * 4);
  iVar4 = r_lld_read_clock();
  uVar8 = (iVar4 - param_2 & 0xfffffffU) + 1 >> 1;
  bVar1 = *(byte *)(iVar3 + 0x52);
  if (*(char *)(iVar3 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 0x40);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x44);
    *(uint *)(iVar3 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar3 + 0x4d) * 2) +
         *(int *)(iVar3 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar7 = DAT_00013036;
    if (DAT_00013036 < *(byte *)(iVar3 + 0x16)) {
      bVar7 = *(byte *)(iVar3 + 0x16);
    }
    *(byte *)(iVar3 + 0x16) = bVar7;
    *(ushort *)(iVar3 + 0x14) = DAT_00013037 & 0xf | 0x2000;
    iVar5 = r_sch_arb_insert(iVar3);
    if (iVar5 == 0) {
      uVar9 = (uint)*(byte *)(iVar3 + 0x4d);
      uVar8 = *(uint *)(iVar3 + 0x48);
      *(char *)(iVar3 + 0x3e) = (1 < uVar9) + '\x02';
      if ((uVar9 << 4 & 0xffffffcf) != 0) {
        r_assert_err("lld_init.c",0x1bf);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      iVar4 = (uint)bVar1 * 0x5a;
      uVar2 = *(ushort *)(iVar5 + iVar4 + 4);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar4 + 4) = uVar2 & 0xffcf | (ushort)(uVar9 << 4);
      uVar2 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar9 * 2);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar4 + 0x20) = (ushort)(((uint)uVar2 + uVar8 + 0x270) / 0x271) & 0xff;
      if (uVar8 < 0x4000) {
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar5 + iVar4 + 0x1a) = (short)(uVar8 + 1 >> 1);
      }
      else {
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar5 + iVar4 + 0x1a) = (ushort)((uVar8 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar8 = (uint)*(byte *)(iVar3 + 0x4c) << 10;
      if ((uVar8 & 0x30000) != 0) {
        r_assert_err(0,"lld_init.c",0x635);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar5 + iVar4 + 0x26);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + 0x26 + iVar5) = uVar2 & 0x3ff | (ushort)uVar8;
      goto _L81;
    }
    *(undefined1 *)(iVar3 + 0x3d) = 0;
  }
  if (uVar8 < *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) - uVar8;
  }
  else {
    r_sch_slice_bg_remove(1);
    if (_sch_slice_params == -1) {
      *(uint *)(iVar3 + 4) =
           ((uint)*(ushort *)(iVar3 + 0x2c) - (uint)*(ushort *)(iVar3 + 0x2e)) * 2 + iVar4 &
           0xffffffc;
    }
    else {
      *(int *)(iVar3 + 4) = _sch_slice_params;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(uint *)(iVar3 + 0x24) = (uint)*(ushort *)(iVar3 + 0x2e);
  }
  iVar4 = *(int *)(iVar3 + 0x24);
  uVar8 = iVar4 * 0x4e2;
  if (_r_assert_param < uVar8) {
    uVar8 = (uint)_r_assert_param;
  }
  *(uint *)(iVar3 + 0x10) = uVar8;
  if (param_3 == 0) {
    *(undefined1 *)(iVar3 + 0x16) = DAT_0001303a;
    *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar3 + 4);
  }
  *(ushort *)(iVar3 + 0x14) = DAT_0001303b & 0xf | 0x6000;
  *(undefined1 *)(iVar3 + 0x3e) = 1;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  iVar5 = (uint)bVar1 * 0x5a;
  *(short *)(iVar6 + iVar5 + 0x20) = (short)iVar4;
  iVar4 = *(int *)(iVar3 + 0x24);
  if (iVar4 << 0x10 < 0) {
    r_assert_err(0,"lld_init.c",0x4ab);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + iVar5 + 0x1a) = (ushort)iVar4 | 0x8000;
  iVar4 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 0x46 + iVar4) = 0;
  iVar4 = r_sch_arb_insert(iVar3);
  if (iVar4 != 0) {
    r_assert_err(0,"lld_init.c",0x278);
    return;
  }
_L81:
  *(undefined1 *)(iVar3 + 0x50) = 0;
  return;
}

