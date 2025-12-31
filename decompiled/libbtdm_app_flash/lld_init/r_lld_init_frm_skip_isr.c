/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010802) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_skip_isr(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  ushort uVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  
  if (_lld_init_env == 0) {
    uVar9 = 0x53a;
_L261:
    r_assert_err(0,0x10000,uVar9);
    return;
  }
  iVar4 = *(int *)(_lld_init_env + param_1 * 4);
  if (iVar4 == 0) {
    uVar9 = 0x53a;
    goto _L261;
  }
  iVar8 = r_lld_read_clock();
  r_ble_log_internal_x2
            (0x404200ff,iVar8,CONCAT11(*(undefined1 *)(iVar4 + 0x31),*(undefined1 *)(iVar4 + 0x52)))
  ;
  cVar3 = *(char *)(iVar4 + 0x31);
  *(undefined1 *)(iVar4 + 0x31) = 0;
  if (cVar3 == '\x02') {
    uVar13 = 0;
    while( true ) {
      iVar8 = uVar13 * 4;
      iVar4 = *(int *)(_lld_init_env + iVar8);
      if (iVar4 != 0) {
        r_ble_log_internal_x2
                  (0x400200fa,*(undefined4 *)(iVar4 + 0x24),
                   (uint)*(byte *)(iVar4 + 0x31) << 0x18 |
                   (uint)*(byte *)(iVar4 + 0x52) << 8 | (uint)*(byte *)(iVar4 + 0x50) << 0x10 |
                   uVar13);
        if (*(char *)(iVar4 + 0x31) == '\0') {
          r_sch_arb_remove(iVar4,0);
          r_sch_slice_bg_remove(1);
          r_ke_free(*(undefined4 *)(_lld_init_env + iVar8));
          iVar4 = _lld_init_env;
          *(undefined4 *)(iVar8 + _lld_init_env) = 0;
          *(byte *)(iVar4 + 0x2b) = ~(byte)(1 << uVar13) & *(byte *)(iVar4 + 0x2b);
        }
        else if (*(char *)(iVar4 + 0x31) == '\x01') {
          bVar2 = *(byte *)(iVar4 + 0x52);
          iVar8 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar8) = 1;
          _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
          *(undefined1 *)(iVar4 + 0x31) = 2;
        }
      }
      if (uVar13 != 0) break;
      uVar13 = 1;
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
  r_sch_arb_remove(iVar4,1);
  bVar2 = rwip_priority;
  if ((uint)*(ushort *)(iVar4 + 0x2c) << 1 <= (iVar8 - *(int *)(iVar4 + 0x28) & 0xfffffffU)) {
    if (0xff < (uint)*(byte *)(iVar4 + 0x16) + (uint)rwip_priority) {
      r_assert_err(0,0x10000,0x520);
    }
    *(int *)(iVar4 + 0x28) = iVar8;
    *(byte *)(iVar4 + 0x16) = bVar2 + *(char *)(iVar4 + 0x16);
  }
  if (*(char *)(iVar4 + 0x3d) != '\x01') {
    iVar4 = r_sch_arb_insert(iVar4);
    uVar9 = 0x52c;
    if (iVar4 == 0) {
      return;
    }
    goto _L261;
  }
  *(undefined1 *)(iVar4 + 0x3d) = 0;
  iVar4 = *(int *)(_lld_init_env + param_1 * 4);
  iVar7 = r_lld_read_clock();
  bVar2 = *(byte *)(iVar4 + 0x52);
  uVar13 = (iVar7 - iVar8 & 0xfffffffU) + 1 >> 1;
  if (*(char *)(iVar4 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 0x40);
    *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 0x44);
    *(uint *)(iVar4 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar4 + 0x4d) * 2) +
         *(int *)(iVar4 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar11 = DAT_0001303e;
    if (DAT_0001303e < *(byte *)(iVar4 + 0x16)) {
      bVar11 = *(byte *)(iVar4 + 0x16);
    }
    *(byte *)(iVar4 + 0x16) = bVar11;
    *(ushort *)(iVar4 + 0x14) = DAT_0001303f & 0xf | 0x2000;
    iVar8 = r_sch_arb_insert(iVar4);
    if (iVar8 == 0) {
      uVar12 = (uint)*(byte *)(iVar4 + 0x4d);
      uVar13 = *(uint *)(iVar4 + 0x48);
      *(char *)(iVar4 + 0x3e) = (1 < uVar12) + '\x02';
      if ((uVar12 << 4 & 0xffffffcf) != 0) {
        r_assert_err(0x10000,0x1bf);
      }
      iVar7 = (uint)bVar2 * 0x5a;
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(ushort *)(iVar8 + iVar7 + 4);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7 + 4) = uVar5 & 0xffcf | (ushort)(uVar12 << 4);
      uVar5 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar12 * 2);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + 0x20 + iVar8) = (ushort)(((uint)uVar5 + uVar13 + 0x270) / 0x271) & 0xff;
      if (uVar13 < 0x4000) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        uVar5 = (ushort)(uVar13 + 1 >> 1);
      }
      else {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        uVar5 = (ushort)((uVar13 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      *(ushort *)(iVar8 + iVar7 + 0x1a) = uVar5;
      uVar13 = (uint)*(byte *)(iVar4 + 0x4c) << 10;
      if ((uVar13 & 0x30000) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(ushort *)(iVar8 + iVar7 + 0x26);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar7 + 0x26) = uVar5 & 0x3ff | (ushort)uVar13;
      goto _L84;
    }
    *(undefined1 *)(iVar4 + 0x3d) = 0;
  }
  if (uVar13 < *(uint *)(iVar4 + 0x24)) {
    uVar13 = *(uint *)(iVar4 + 0x24) - uVar13;
  }
  else {
    r_sch_slice_bg_remove(1);
    uVar13 = (uint)*(ushort *)(iVar4 + 0x2e);
    uVar12 = _sch_slice_params;
    if (_sch_slice_params == 0xffffffff) {
      uVar12 = (*(ushort *)(iVar4 + 0x2c) - uVar13) * 2 + iVar7 & 0xffffffc;
    }
    *(uint *)(iVar4 + 4) = uVar12;
    *(undefined4 *)(iVar4 + 8) = 0;
  }
  uVar10 = (uint)_r_assert_param;
  *(uint *)(iVar4 + 0x24) = uVar13;
  uVar12 = uVar13 * 0x4e2;
  if (uVar10 < uVar13 * 0x4e2) {
    uVar12 = uVar10;
  }
  *(uint *)(iVar4 + 0x10) = uVar12;
  iVar7 = (uint)bVar2 * 0x5a;
  *(ushort *)(iVar4 + 0x14) = DAT_00013043 & 0xf | 0x6000;
  *(undefined1 *)(iVar4 + 0x3e) = 1;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar7 + 0x20 + iVar8) = (short)uVar13;
  uVar13 = *(uint *)(iVar4 + 0x24);
  if ((uVar13 >> 0xf & 1) != 0) {
    r_assert_err(0,0x10000,0x4ab);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar7 + 0x1a + iVar8) = (ushort)uVar13 | 0x8000;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar7 + 0x46 + iVar8) = 0;
  iVar8 = r_sch_arb_insert(iVar4);
  if (iVar8 != 0) {
    r_assert_err(0,0x10000,0x280);
    return;
  }
_L84:
  *(undefined1 *)(iVar4 + 0x50) = 0;
  return;
}

