/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000107c4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  
  if (param_1 == 0) {
    uVar7 = 0x5ba;
_L92:
    r_assert_err(0,"lld_init.c",uVar7);
    return;
  }
  if (*(char *)(param_1 + 0x31) != '\0') {
    r_assert_param(*(undefined1 *)(param_1 + 0x51),"lld_init.c",0x5b5);
    return;
  }
  iVar6 = r_lld_read_clock();
  bVar1 = rwip_priority;
  if ((uint)*(ushort *)(param_1 + 0x2c) << 1 <= (iVar6 - *(int *)(param_1 + 0x28) & 0xfffffffU)) {
    if (0xff < (uint)*(byte *)(param_1 + 0x16) + (uint)rwip_priority) {
      r_assert_err(0,"lld_init.c",0x59c);
    }
    *(int *)(param_1 + 0x28) = iVar6;
    *(byte *)(param_1 + 0x16) = bVar1 + *(char *)(param_1 + 0x16);
  }
  if (*(char *)(param_1 + 0x3d) != '\x01') {
    iVar6 = r_sch_arb_insert(param_1);
    if (iVar6 == 0) {
      return;
    }
    uVar7 = 0x5a8;
    goto _L92;
  }
  *(undefined1 *)(param_1 + 0x3d) = 0;
  iVar3 = *(int *)(_lld_init_env + (uint)*(byte *)(param_1 + 0x51) * 4);
  iVar4 = r_lld_read_clock();
  uVar9 = (iVar4 - iVar6 & 0xfffffffU) + 1 >> 1;
  bVar1 = *(byte *)(iVar3 + 0x52);
  if (*(char *)(iVar3 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 0x40);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x44);
    *(uint *)(iVar3 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar3 + 0x4d) * 2) +
         *(int *)(iVar3 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar8 = DAT_00013036;
    if (DAT_00013036 < *(byte *)(iVar3 + 0x16)) {
      bVar8 = *(byte *)(iVar3 + 0x16);
    }
    *(byte *)(iVar3 + 0x16) = bVar8;
    *(ushort *)(iVar3 + 0x14) = DAT_00013037 & 0xf | 0x2000;
    iVar6 = r_sch_arb_insert(iVar3);
    if (iVar6 == 0) {
      uVar10 = (uint)*(byte *)(iVar3 + 0x4d);
      uVar9 = *(uint *)(iVar3 + 0x48);
      *(char *)(iVar3 + 0x3e) = (1 < uVar10) + '\x02';
      if ((uVar10 << 4 & 0xffffffcf) != 0) {
        r_assert_err("lld_init.c",0x1bf);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      iVar6 = (uint)bVar1 * 0x5a;
      uVar2 = *(ushort *)(iVar4 + iVar6 + 4);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + iVar6 + 4) = uVar2 & 0xffcf | (ushort)(uVar10 << 4);
      uVar2 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar10 * 2);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar4 + iVar6 + 0x20) = (ushort)(((uint)uVar2 + uVar9 + 0x270) / 0x271) & 0xff;
      if (uVar9 < 0x4000) {
        iVar4 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar4 + iVar6 + 0x1a) = (short)(uVar9 + 1 >> 1);
      }
      else {
        iVar4 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar4 + iVar6 + 0x1a) = (ushort)((uVar9 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar9 = (uint)*(byte *)(iVar3 + 0x4c) << 10;
      if ((uVar9 & 0x30000) != 0) {
        r_assert_err(0,"lld_init.c",0x635);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      uVar2 = *(ushort *)(iVar4 + iVar6 + 0x26);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + 0x26 + iVar4) = uVar2 & 0x3ff | (ushort)uVar9;
      goto _L81;
    }
    *(undefined1 *)(iVar3 + 0x3d) = 0;
  }
  if (uVar9 < *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) - uVar9;
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
  iVar6 = *(int *)(iVar3 + 0x24);
  uVar9 = iVar6 * 0x4e2;
  if (_r_assert_param < uVar9) {
    uVar9 = (uint)_r_assert_param;
  }
  *(uint *)(iVar3 + 0x10) = uVar9;
  *(ushort *)(iVar3 + 0x14) = DAT_0001303b & 0xf | 0x6000;
  *(undefined1 *)(iVar3 + 0x3e) = 1;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  iVar4 = (uint)bVar1 * 0x5a;
  *(short *)(iVar5 + iVar4 + 0x20) = (short)iVar6;
  iVar6 = *(int *)(iVar3 + 0x24);
  if (iVar6 << 0x10 < 0) {
    r_assert_err(0,"lld_init.c",0x4ab);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + iVar4 + 0x1a) = (ushort)iVar6 | 0x8000;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar4 + 0x46 + iVar6) = 0;
  iVar6 = r_sch_arb_insert(iVar3);
  if (iVar6 != 0) {
    r_assert_err(0,"lld_init.c",0x278);
    return;
  }
_L81:
  *(undefined1 *)(iVar3 + 0x50) = 0;
  return;
}

