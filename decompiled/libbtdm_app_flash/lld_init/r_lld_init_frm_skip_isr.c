/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010824) */
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
    uVar9 = 0x512;
_L280:
    r_assert_err(0,0x10000,uVar9);
    return;
  }
  iVar4 = *(int *)(_lld_init_env + param_1 * 4);
  if (iVar4 == 0) {
    uVar9 = 0x512;
    goto _L280;
  }
  iVar7 = r_lld_read_clock();
  iVar8 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar8 + 0x28) & 0x10) != 0) &&
     (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
    r_ble_log_internal_x2
              (0x404f0005,CONCAT11(*(undefined1 *)(iVar4 + 0x31),*(undefined1 *)(iVar4 + 0x52)),
               iVar7);
  }
  cVar3 = *(char *)(iVar4 + 0x31);
  *(undefined1 *)(iVar4 + 0x31) = 0;
  if (cVar3 == '\x02') {
    uVar12 = 0;
    while( true ) {
      iVar7 = uVar12 * 4;
      iVar4 = *(int *)(_lld_init_env + iVar7);
      if (iVar4 != 0) {
        iVar8 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar8 + 0x28) & 0x10) != 0) &&
           (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
          r_ble_log_internal_x2
                    (0x400f0002,
                     (uint)*(byte *)(iVar4 + 0x52) << 8 |
                     (uint)*(byte *)(iVar4 + 0x31) << 0x18 | (uint)*(byte *)(iVar4 + 0x50) << 0x10 |
                     uVar12,*(undefined4 *)(iVar4 + 0x24));
        }
        if (*(char *)(iVar4 + 0x31) == '\0') {
          r_sch_arb_remove(iVar4,0);
          r_sch_slice_bg_remove(1);
          r_ke_free(*(undefined4 *)(_lld_init_env + iVar7));
          iVar4 = _lld_init_env;
          *(undefined4 *)(iVar7 + _lld_init_env) = 0;
          *(byte *)(iVar4 + 0x2b) = ~(byte)(1 << uVar12) & *(byte *)(iVar4 + 0x2b);
        }
        else if (*(char *)(iVar4 + 0x31) == '\x01') {
          bVar2 = *(byte *)(iVar4 + 0x52);
          iVar7 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar7) = 1;
          _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
          *(undefined1 *)(iVar4 + 0x31) = 2;
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
  r_sch_arb_remove(iVar4,1);
  bVar2 = rwip_priority;
  if ((uint)*(ushort *)(iVar4 + 0x2c) << 1 <= (iVar7 - *(int *)(iVar4 + 0x28) & 0xfffffffU)) {
    if (0xff < (uint)*(byte *)(iVar4 + 0x16) + (uint)rwip_priority) {
      r_assert_err(0,0x10000,0x4f8);
    }
    *(int *)(iVar4 + 0x28) = iVar7;
    *(byte *)(iVar4 + 0x16) = bVar2 + *(char *)(iVar4 + 0x16);
  }
  if (*(char *)(iVar4 + 0x3d) != '\x01') {
    iVar4 = r_sch_arb_insert(iVar4);
    uVar9 = 0x504;
    if (iVar4 == 0) {
      return;
    }
    goto _L280;
  }
  *(undefined1 *)(iVar4 + 0x3d) = 0;
  iVar4 = *(int *)(_lld_init_env + param_1 * 4);
  iVar8 = r_lld_read_clock();
  bVar2 = *(byte *)(iVar4 + 0x52);
  uVar12 = (iVar8 - iVar7 & 0xfffffffU) + 1 >> 1;
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
    iVar7 = r_sch_arb_insert(iVar4);
    if (iVar7 == 0) {
      uVar13 = (uint)*(byte *)(iVar4 + 0x4d);
      uVar12 = *(uint *)(iVar4 + 0x48);
      *(char *)(iVar4 + 0x3e) = (1 < uVar13) + '\x02';
      if ((uVar13 << 4 & 0xffffffcf) != 0) {
        r_assert_err(0x10000,0x1bf);
      }
      iVar8 = (uint)bVar2 * 0x5a;
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(ushort *)(iVar7 + iVar8 + 4);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar8 + 4) = uVar5 & 0xffcf | (ushort)(uVar13 << 4);
      uVar5 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar13 * 2);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + 0x20 + iVar7) = (ushort)(((uint)uVar5 + uVar12 + 0x270) / 0x271) & 0xff;
      if (uVar12 < 0x4000) {
        iVar7 = r_emi_get_mem_addr_by_offset(0x400);
        uVar5 = (ushort)(uVar12 + 1 >> 1);
      }
      else {
        iVar7 = r_emi_get_mem_addr_by_offset(0x400);
        uVar5 = (ushort)((uVar12 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      *(ushort *)(iVar7 + iVar8 + 0x1a) = uVar5;
      uVar12 = (uint)*(byte *)(iVar4 + 0x4c) << 10;
      if ((uVar12 & 0x30000) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(ushort *)(iVar7 + iVar8 + 0x26);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar8 + 0x26) = uVar5 & 0x3ff | (ushort)uVar12;
      goto _L90;
    }
    *(undefined1 *)(iVar4 + 0x3d) = 0;
  }
  if (uVar12 < *(uint *)(iVar4 + 0x24)) {
    uVar12 = *(uint *)(iVar4 + 0x24) - uVar12;
  }
  else {
    r_sch_slice_bg_remove(1);
    uVar12 = (uint)*(ushort *)(iVar4 + 0x2e);
    uVar13 = _sch_slice_params;
    if (_sch_slice_params == 0xffffffff) {
      uVar13 = (*(ushort *)(iVar4 + 0x2c) - uVar12) * 2 + iVar8 & 0xffffffc;
    }
    *(uint *)(iVar4 + 4) = uVar13;
    *(undefined4 *)(iVar4 + 8) = 0;
  }
  uVar10 = (uint)_r_assert_param;
  *(uint *)(iVar4 + 0x24) = uVar12;
  uVar13 = uVar12 * 0x4e2;
  if (uVar10 < uVar12 * 0x4e2) {
    uVar13 = uVar10;
  }
  *(uint *)(iVar4 + 0x10) = uVar13;
  iVar8 = (uint)bVar2 * 0x5a;
  *(ushort *)(iVar4 + 0x14) = DAT_00013043 & 0xf | 0x6000;
  *(undefined1 *)(iVar4 + 0x3e) = 1;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar8 + 0x20 + iVar7) = (short)uVar12;
  uVar12 = *(uint *)(iVar4 + 0x24);
  if ((uVar12 >> 0xf & 1) != 0) {
    r_assert_err(0,0x10000,0x4ab);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + 0x1a + iVar7) = (ushort)uVar12 | 0x8000;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar8 + 0x46 + iVar7) = 0;
  iVar7 = r_sch_arb_insert(iVar4);
  if (iVar7 != 0) {
    r_assert_err(0,0x10000,0x27b);
    return;
  }
_L90:
  *(undefined1 *)(iVar4 + 0x50) = 0;
  return;
}

