/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010840) */
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
  int iVar9;
  undefined4 uVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  
  if (_lld_init_env == 0) {
    uVar10 = 0x512;
_L278:
    r_assert_err(0,"lld_init.c",uVar10);
    return;
  }
  iVar5 = *(int *)(_lld_init_env + param_1 * 4);
  if (iVar5 == 0) {
    uVar10 = 0x512;
    goto _L278;
  }
  iVar8 = r_lld_read_clock();
  iVar9 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar9 + 0x28) & 0x10) != 0) &&
     (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
    r_ble_log_internal_x2
              (0x404f0005,CONCAT11(*(undefined1 *)(iVar5 + 0x31),*(undefined1 *)(iVar5 + 0x52)),
               iVar8);
  }
  cVar3 = *(char *)(iVar5 + 0x31);
  *(undefined1 *)(iVar5 + 0x31) = 0;
  if (cVar3 == '\x02') {
    uVar12 = 0;
    while( true ) {
      iVar8 = uVar12 * 4;
      iVar5 = *(int *)(_lld_init_env + iVar8);
      if (iVar5 != 0) {
        iVar9 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar9 + 0x28) & 0x10) != 0) &&
           (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
          r_ble_log_internal_x2
                    (0x400f0002,
                     (uint)*(byte *)(iVar5 + 0x52) << 8 |
                     (uint)*(byte *)(iVar5 + 0x31) << 0x18 | (uint)*(byte *)(iVar5 + 0x50) << 0x10 |
                     uVar12,*(undefined4 *)(iVar5 + 0x24));
        }
        if (*(char *)(iVar5 + 0x31) == '\0') {
          r_sch_arb_remove(iVar5,0);
          r_sch_slice_bg_remove(1);
          r_ke_free(*(undefined4 *)(_lld_init_env + iVar8));
          iVar5 = _lld_init_env;
          *(undefined4 *)(iVar8 + _lld_init_env) = 0;
          *(byte *)(iVar5 + 0x2b) = ~(byte)(1 << uVar12) & *(byte *)(iVar5 + 0x2b);
        }
        else if (*(char *)(iVar5 + 0x31) == '\x01') {
          bVar2 = *(byte *)(iVar5 + 0x52);
          iVar8 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar8 + (uint)bVar2 * 0x5a + 0x20) = 1;
          _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
          *(undefined1 *)(iVar5 + 0x31) = 2;
        }
      }
      if (uVar12 != 0) break;
      uVar12 = 1;
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
      r_assert_err(0,"lld_init.c",0x4f8);
    }
    *(int *)(iVar5 + 0x28) = iVar8;
    *(byte *)(iVar5 + 0x16) = bVar2 + *(char *)(iVar5 + 0x16);
  }
  if (*(char *)(iVar5 + 0x3d) != '\x01') {
    iVar5 = r_sch_arb_insert(iVar5);
    uVar10 = 0x504;
    if (iVar5 == 0) {
      return;
    }
    goto _L278;
  }
  *(undefined1 *)(iVar5 + 0x3d) = 0;
  iVar5 = *(int *)(_lld_init_env + param_1 * 4);
  iVar9 = r_lld_read_clock();
  uVar12 = (iVar9 - iVar8 & 0xfffffffU) + 1 >> 1;
  bVar2 = *(byte *)(iVar5 + 0x52);
  if (*(char *)(iVar5 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar5 + 0x40);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 0x44);
    *(uint *)(iVar5 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar5 + 0x4d) * 2) +
         *(int *)(iVar5 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar11 = DAT_0001303e;
    if (DAT_0001303e < *(byte *)(iVar5 + 0x16)) {
      bVar11 = *(byte *)(iVar5 + 0x16);
    }
    *(byte *)(iVar5 + 0x16) = bVar11;
    *(ushort *)(iVar5 + 0x14) = DAT_0001303f & 0xf | 0x2000;
    iVar8 = r_sch_arb_insert(iVar5);
    if (iVar8 == 0) {
      uVar13 = (uint)*(byte *)(iVar5 + 0x4d);
      uVar12 = *(uint *)(iVar5 + 0x48);
      *(char *)(iVar5 + 0x3e) = (1 < uVar13) + '\x02';
      if ((uVar13 << 4 & 0xffffffcf) != 0) {
        r_assert_err("lld_init.c",0x1bf);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      iVar8 = (uint)bVar2 * 0x5a;
      uVar4 = *(ushort *)(iVar9 + iVar8 + 4);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + iVar8 + 4) = uVar4 & 0xffcf | (ushort)(uVar13 << 4);
      uVar4 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar13 * 2);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + iVar8 + 0x20) = (ushort)(((uint)uVar4 + uVar12 + 0x270) / 0x271) & 0xff;
      if (uVar12 < 0x4000) {
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar9 + iVar8 + 0x1a) = (short)(uVar12 + 1 >> 1);
      }
      else {
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar9 + iVar8 + 0x1a) = (ushort)((uVar12 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar12 = (uint)*(byte *)(iVar5 + 0x4c) << 10;
      if ((uVar12 & 0x30000) != 0) {
        r_assert_err(0,"lld_init.c",0x635);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar9 + iVar8 + 0x26);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + 0x26 + iVar9) = uVar4 & 0x3ff | (ushort)uVar12;
      goto _L87;
    }
    *(undefined1 *)(iVar5 + 0x3d) = 0;
  }
  if (uVar12 < *(uint *)(iVar5 + 0x24)) {
    *(uint *)(iVar5 + 0x24) = *(uint *)(iVar5 + 0x24) - uVar12;
  }
  else {
    r_sch_slice_bg_remove(1);
    if (_sch_slice_params == -1) {
      *(uint *)(iVar5 + 4) =
           ((uint)*(ushort *)(iVar5 + 0x2c) - (uint)*(ushort *)(iVar5 + 0x2e)) * 2 + iVar9 &
           0xffffffc;
    }
    else {
      *(int *)(iVar5 + 4) = _sch_slice_params;
    }
    *(undefined4 *)(iVar5 + 8) = 0;
    *(uint *)(iVar5 + 0x24) = (uint)*(ushort *)(iVar5 + 0x2e);
  }
  iVar8 = *(int *)(iVar5 + 0x24);
  uVar12 = iVar8 * 0x4e2;
  if (_r_assert_param < uVar12) {
    uVar12 = (uint)_r_assert_param;
  }
  *(uint *)(iVar5 + 0x10) = uVar12;
  *(ushort *)(iVar5 + 0x14) = DAT_00013043 & 0xf | 0x6000;
  *(undefined1 *)(iVar5 + 0x3e) = 1;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  iVar9 = (uint)bVar2 * 0x5a;
  *(short *)(iVar7 + iVar9 + 0x20) = (short)iVar8;
  iVar8 = *(int *)(iVar5 + 0x24);
  if (iVar8 << 0x10 < 0) {
    r_assert_err(0,"lld_init.c",0x4ab);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar7 + iVar9 + 0x1a) = (ushort)iVar8 | 0x8000;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar9 + 0x46 + iVar8) = 0;
  iVar8 = r_sch_arb_insert(iVar5);
  if (iVar8 != 0) {
    r_assert_err(0,"lld_init.c",0x27b);
    return;
  }
_L87:
  *(undefined1 *)(iVar5 + 0x50) = 0;
  return;
}

