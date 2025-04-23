/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000107ce) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_skip_isr(int param_1)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  byte bVar15;
  
  if (_lld_init_env == 0) {
    uVar12 = 0x512;
_L275:
    r_assert_err(0,0x10000,uVar12);
    return;
  }
  iVar5 = *(int *)(_lld_init_env + param_1 * 4);
  if (iVar5 == 0) {
    uVar12 = 0x512;
    goto _L275;
  }
  iVar10 = r_lld_read_clock();
  iVar11 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar11 + 0x28) & 0x10) != 0) &&
     (iVar11 = r_sdk_config_get_opts_ext(), *(byte *)(iVar11 + 0x2c) < 3)) {
    r_ble_log_internal_x2
              (0x404f0005,CONCAT11(*(undefined1 *)(iVar5 + 0x31),*(undefined1 *)(iVar5 + 0x52)),
               iVar10);
  }
  cVar4 = *(char *)(iVar5 + 0x31);
  *(undefined1 *)(iVar5 + 0x31) = 0;
  if (cVar4 == '\x02') {
    uVar7 = 0;
    do {
      iVar10 = uVar7 * 4;
      iVar5 = *(int *)(_lld_init_env + iVar10);
      if (iVar5 != 0) {
        iVar11 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar11 + 0x28) & 0x10) != 0) &&
           (iVar11 = r_sdk_config_get_opts_ext(), *(byte *)(iVar11 + 0x2c) < 3)) {
          r_ble_log_internal_x2
                    (0x400f0002,
                     (uint)*(byte *)(iVar5 + 0x52) << 8 |
                     (uint)*(byte *)(iVar5 + 0x31) << 0x18 | (uint)*(byte *)(iVar5 + 0x50) << 0x10 |
                     uVar7,*(undefined4 *)(iVar5 + 0x24));
        }
        if (*(char *)(iVar5 + 0x31) == '\0') {
          r_sch_arb_remove(iVar5,0);
          r_sch_slice_bg_remove(1);
          r_ke_free(*(undefined4 *)(_lld_init_env + iVar10));
          iVar5 = _lld_init_env;
          *(undefined4 *)(iVar10 + _lld_init_env) = 0;
          *(byte *)(iVar5 + 0x2b) = ~(byte)(1 << uVar7) & *(byte *)(iVar5 + 0x2b);
        }
        else if (*(char *)(iVar5 + 0x31) == '\x01') {
          bVar3 = *(byte *)(iVar5 + 0x52);
          iVar10 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)((uint)bVar3 * 0x5a + 0x20 + iVar10) = 1;
          _DAT_60031000 = _DAT_60031000 | 0x1000000;
          *(undefined1 *)(iVar5 + 0x31) = 2;
        }
      }
      bVar1 = uVar7 != 1;
      uVar7 = 1;
    } while (bVar1);
    if (*(char *)(_lld_init_env + 0x2b) == '\0') {
      if (*(int *)(_lld_init_env + 8) == 0) {
        puVar8 = (undefined1 *)r_ke_msg_alloc(0x209,0,0xff,0x38);
        uVar2 = *(undefined1 *)(_lld_init_env + 0x2c);
        puVar8[1] = 0;
        *puVar8 = uVar2;
      }
      r_ke_msg_send();
      r_ke_free(_lld_init_env);
      _lld_init_env = 0;
    }
    return;
  }
  r_sch_arb_remove(iVar5,1);
  bVar3 = rwip_priority;
  if ((uint)*(ushort *)(iVar5 + 0x2c) << 1 <= (iVar10 - *(int *)(iVar5 + 0x28) & 0xfffffffU)) {
    if (0xff < (uint)*(byte *)(iVar5 + 0x16) + (uint)rwip_priority) {
      r_assert_err(0,0x10000,0x4f8);
    }
    *(int *)(iVar5 + 0x28) = iVar10;
    *(byte *)(iVar5 + 0x16) = bVar3 + *(char *)(iVar5 + 0x16);
  }
  if (*(char *)(iVar5 + 0x3d) != '\x01') {
    iVar5 = r_sch_arb_insert(iVar5);
    uVar12 = 0x504;
    if (iVar5 == 0) {
      return;
    }
    goto _L275;
  }
  *(undefined1 *)(iVar5 + 0x3d) = 0;
  iVar5 = *(int *)(_lld_init_env + param_1 * 4);
  iVar11 = r_lld_read_clock();
  bVar3 = *(byte *)(iVar5 + 0x52);
  uVar7 = (iVar11 - iVar10 & 0xfffffffU) + 1 >> 1;
  if (*(char *)(iVar5 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove();
    *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar5 + 0x40);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 0x44);
    *(uint *)(iVar5 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar5 + 0x4d) * 2) +
         *(int *)(iVar5 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar15 = DAT_0001303e;
    if (DAT_0001303e < *(byte *)(iVar5 + 0x16)) {
      bVar15 = *(byte *)(iVar5 + 0x16);
    }
    *(byte *)(iVar5 + 0x16) = bVar15;
    *(ushort *)(iVar5 + 0x14) = DAT_0001303f & 0xf | 0x2000;
    iVar10 = r_sch_arb_insert(iVar5);
    if (iVar10 == 0) {
      bVar15 = *(byte *)(iVar5 + 0x4d);
      uVar7 = *(uint *)(iVar5 + 0x48);
      *(char *)(iVar5 + 0x3e) = (1 < bVar15) + '\x02';
      if ((bVar15 & 0xfc) != 0) {
        r_assert_err(0x10000,0x1bf);
      }
      iVar11 = (uint)bVar3 * 0x5a;
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar6 = *(ushort *)(iVar10 + iVar11 + 4);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar10 + iVar11 + 4) = uVar6 & 0xffcf | (ushort)bVar15 << 4;
      uVar6 = *(ushort *)(&lld_init_max_aux_dur_tab + (uint)bVar15 * 2);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar11 + 0x20 + iVar10) = (ushort)(((uint)uVar6 + uVar7 + 0x270) / 0x271) & 0xff;
      if (uVar7 < 0x4000) {
        iVar10 = r_emi_get_mem_addr_by_offset(0x400);
        uVar6 = (ushort)(uVar7 + 1 >> 1);
      }
      else {
        iVar10 = r_emi_get_mem_addr_by_offset(0x400);
        uVar6 = (ushort)((uVar7 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      *(ushort *)(iVar10 + iVar11 + 0x1a) = uVar6;
      bVar3 = *(byte *)(iVar5 + 0x4c);
      if ((bVar3 & 0xc0) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar6 = *(ushort *)(iVar10 + iVar11 + 0x26);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar10 + iVar11 + 0x26) = uVar6 & 0x3ff | (ushort)bVar3 << 10;
      goto _L88;
    }
    *(undefined1 *)(iVar5 + 0x3d) = 0;
  }
  if (uVar7 < *(uint *)(iVar5 + 0x24)) {
    uVar7 = *(uint *)(iVar5 + 0x24) - uVar7;
  }
  else {
    r_sch_slice_bg_remove(1);
    uVar7 = (uint)*(ushort *)(iVar5 + 0x2e);
    uVar14 = _sch_slice_params;
    if (_sch_slice_params == 0xffffffff) {
      uVar14 = (*(ushort *)(iVar5 + 0x2c) - uVar7) * 2 + iVar11 & 0xffffffc;
    }
    *(uint *)(iVar5 + 4) = uVar14;
    *(undefined4 *)(iVar5 + 8) = 0;
  }
  uVar13 = (uint)_r_assert_param;
  *(uint *)(iVar5 + 0x24) = uVar7;
  uVar14 = uVar7 * 0x4e2;
  if (uVar13 < uVar7 * 0x4e2) {
    uVar14 = uVar13;
  }
  *(uint *)(iVar5 + 0x10) = uVar14;
  iVar11 = (uint)bVar3 * 0x5a;
  *(ushort *)(iVar5 + 0x14) = DAT_00013043 & 0xf | 0x6000;
  *(undefined1 *)(iVar5 + 0x3e) = 1;
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar11 + 0x20 + iVar10) = (short)uVar7;
  iVar10 = *(int *)(iVar5 + 0x24);
  if (iVar10 << 0x10 < 0) {
    r_assert_err(0,0x10000,0x4ab);
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar11 + 0x1a + iVar9) = (ushort)iVar10 | 0x8000;
  iVar10 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar11 + 0x46 + iVar10) = 0;
  iVar10 = r_sch_arb_insert(iVar5);
  if (iVar10 != 0) {
    r_assert_err(0,0x10000,0x27b);
    return;
  }
_L88:
  *(undefined1 *)(iVar5 + 0x50) = 0;
  return;
}

