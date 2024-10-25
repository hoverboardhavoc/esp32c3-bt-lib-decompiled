/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000107c4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_skip_isr(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  
  if (_lld_init_env == 0) {
    uVar9 = 0x506;
_L256:
    r_assert_err(0,"lld_init.c",uVar9);
    return;
  }
  iVar5 = *(int *)(_lld_init_env + param_1 * 4);
  if (iVar5 == 0) {
    uVar9 = 0x506;
    goto _L256;
  }
  iVar8 = r_lld_read_clock();
  cVar3 = *(char *)(iVar5 + 0x31);
  *(undefined1 *)(iVar5 + 0x31) = 0;
  if (cVar3 == '\x02') {
    iVar5 = 0;
    while( true ) {
      iVar8 = iVar5 * 4;
      iVar13 = *(int *)(_lld_init_env + iVar8);
      if (iVar13 != 0) {
        if (*(char *)(iVar13 + 0x31) == '\0') {
          r_sch_arb_remove(iVar13,0);
          r_sch_slice_bg_remove(1);
          r_ke_free(*(undefined4 *)(_lld_init_env + iVar8));
          iVar13 = _lld_init_env;
          *(undefined4 *)(iVar8 + _lld_init_env) = 0;
          *(byte *)(iVar13 + 0x2b) = ~(byte)(1 << iVar5) & *(byte *)(iVar13 + 0x2b);
        }
        else if (*(char *)(iVar13 + 0x31) == '\x01') {
          bVar2 = *(byte *)(iVar13 + 0x52);
          iVar8 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar8 + (uint)bVar2 * 0x5a + 0x20) = 1;
          _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
          *(undefined1 *)(iVar13 + 0x31) = 2;
        }
      }
      if (iVar5 != 0) break;
      iVar5 = 1;
    }
    if (*(char *)(_lld_init_env + 0x2b) == '\0') {
      if (*(int *)(_lld_init_env + 8) == 0) {
        puVar6 = (undefined1 *)r_ke_msg_alloc(0x209,0,0xff,0x38);
        uVar1 = *(undefined1 *)(_lld_init_env + 0x2c);
        puVar6[1] = 0;
        *puVar6 = uVar1;
      }
      r_ke_msg_send();
      r_ke_free(_lld_init_env);
      _lld_init_env = 0;
    }
    return;
  }
  r_sch_arb_remove(iVar5,1);
  bVar2 = rwip_priority;
  if ((uint)*(ushort *)(iVar5 + 0x2c) << 1 <= (iVar8 - *(int *)(iVar5 + 0x28) & 0xfffffffU)) {
    if (0xff < (uint)*(byte *)(iVar5 + 0x16) + (uint)rwip_priority) {
      r_assert_err(0,"lld_init.c",0x4ec);
    }
    *(int *)(iVar5 + 0x28) = iVar8;
    *(byte *)(iVar5 + 0x16) = bVar2 + *(char *)(iVar5 + 0x16);
  }
  if (*(char *)(iVar5 + 0x3d) != '\x01') {
    iVar5 = r_sch_arb_insert(iVar5);
    uVar9 = 0x4f8;
    if (iVar5 == 0) {
      return;
    }
    goto _L256;
  }
  *(undefined1 *)(iVar5 + 0x3d) = 0;
  iVar5 = *(int *)(_lld_init_env + param_1 * 4);
  iVar13 = r_lld_read_clock();
  uVar11 = (iVar13 - iVar8 & 0xfffffffU) + 1 >> 1;
  bVar2 = *(byte *)(iVar5 + 0x52);
  if (*(char *)(iVar5 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar5 + 0x40);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 0x44);
    *(uint *)(iVar5 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar5 + 0x4d) * 2) +
         *(int *)(iVar5 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar10 = DAT_00013036;
    if (DAT_00013036 < *(byte *)(iVar5 + 0x16)) {
      bVar10 = *(byte *)(iVar5 + 0x16);
    }
    *(byte *)(iVar5 + 0x16) = bVar10;
    *(ushort *)(iVar5 + 0x14) = DAT_00013037 & 0xf | 0x2000;
    iVar8 = r_sch_arb_insert(iVar5);
    if (iVar8 == 0) {
      uVar12 = (uint)*(byte *)(iVar5 + 0x4d);
      uVar11 = *(uint *)(iVar5 + 0x48);
      *(char *)(iVar5 + 0x3e) = (1 < uVar12) + '\x02';
      if ((uVar12 << 4 & 0xffffffcf) != 0) {
        r_assert_err("lld_init.c",0x1bf);
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      iVar8 = (uint)bVar2 * 0x5a;
      uVar4 = *(ushort *)(iVar13 + iVar8 + 4);
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + iVar8 + 4) = uVar4 & 0xffcf | (ushort)(uVar12 << 4);
      uVar4 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar12 * 2);
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar13 + iVar8 + 0x20) = (ushort)(((uint)uVar4 + uVar11 + 0x270) / 0x271) & 0xff;
      if (uVar11 < 0x4000) {
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar13 + iVar8 + 0x1a) = (short)(uVar11 + 1 >> 1);
      }
      else {
        iVar13 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar13 + iVar8 + 0x1a) = (ushort)((uVar11 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar11 = (uint)*(byte *)(iVar5 + 0x4c) << 10;
      if ((uVar11 & 0x30000) != 0) {
        r_assert_err(0,"lld_init.c",0x635);
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar13 + iVar8 + 0x26);
      iVar13 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + 0x26 + iVar13) = uVar4 & 0x3ff | (ushort)uVar11;
      goto _L81;
    }
    *(undefined1 *)(iVar5 + 0x3d) = 0;
  }
  if (uVar11 < *(uint *)(iVar5 + 0x24)) {
    *(uint *)(iVar5 + 0x24) = *(uint *)(iVar5 + 0x24) - uVar11;
  }
  else {
    r_sch_slice_bg_remove(1);
    if (_sch_slice_params == -1) {
      *(uint *)(iVar5 + 4) =
           ((uint)*(ushort *)(iVar5 + 0x2c) - (uint)*(ushort *)(iVar5 + 0x2e)) * 2 + iVar13 &
           0xffffffc;
    }
    else {
      *(int *)(iVar5 + 4) = _sch_slice_params;
    }
    *(undefined4 *)(iVar5 + 8) = 0;
    *(uint *)(iVar5 + 0x24) = (uint)*(ushort *)(iVar5 + 0x2e);
  }
  iVar8 = *(int *)(iVar5 + 0x24);
  uVar11 = iVar8 * 0x4e2;
  if (_r_assert_param < uVar11) {
    uVar11 = (uint)_r_assert_param;
  }
  *(uint *)(iVar5 + 0x10) = uVar11;
  *(ushort *)(iVar5 + 0x14) = DAT_0001303b & 0xf | 0x6000;
  *(undefined1 *)(iVar5 + 0x3e) = 1;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  iVar13 = (uint)bVar2 * 0x5a;
  *(short *)(iVar7 + iVar13 + 0x20) = (short)iVar8;
  iVar8 = *(int *)(iVar5 + 0x24);
  if (iVar8 << 0x10 < 0) {
    r_assert_err(0,"lld_init.c",0x4ab);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar7 + iVar13 + 0x1a) = (ushort)iVar8 | 0x8000;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar13 + 0x46 + iVar8) = 0;
  iVar8 = r_sch_arb_insert(iVar5);
  if (iVar8 != 0) {
    r_assert_err(0,"lld_init.c",0x278);
    return;
  }
_L81:
  *(undefined1 *)(iVar5 + 0x50) = 0;
  return;
}

