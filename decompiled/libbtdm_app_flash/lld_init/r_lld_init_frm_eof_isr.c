/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_eof_isr(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  int iVar11;
  uint uVar12;
  
  g_initor_evt_end_abort = (undefined1)param_3;
  if (_lld_init_env == 0) {
_L220:
    r_assert_param(param_1,0x10000,0x4f3);
    return;
  }
  iVar11 = *(int *)(_lld_init_env + param_1 * 4);
  if (iVar11 == 0) goto _L220;
  uVar4 = (uint)*(byte *)(iVar11 + 0x52);
  r_ble_log_internal_x1(0x404200fe,param_3 << 8 | uVar4 | (uint)*(byte *)(iVar11 + 0x31) << 0x10);
  cVar3 = *(char *)(iVar11 + 0x31);
  *(undefined1 *)(iVar11 + 0x31) = 0;
  if (cVar3 == '\x02') {
    while (iVar11 = r_lld_rxdesc_check_hack(uVar4), iVar11 != 0) {
      r_lld_rxdesc_free();
    }
    uVar4 = 0;
    while( true ) {
      iVar5 = uVar4 * 4;
      iVar11 = *(int *)(_lld_init_env + iVar5);
      if (iVar11 != 0) {
        r_ble_log_internal_x2
                  (0x400200fa,*(undefined4 *)(iVar11 + 0x24),
                   (uint)*(byte *)(iVar11 + 0x31) << 0x18 |
                   (uint)*(byte *)(iVar11 + 0x52) << 8 | (uint)*(byte *)(iVar11 + 0x50) << 0x10 |
                   uVar4);
        if (*(char *)(iVar11 + 0x31) == '\0') {
          r_sch_arb_remove(iVar11,0);
          r_sch_slice_bg_remove(1);
          r_ke_free(*(undefined4 *)(_lld_init_env + iVar5));
          iVar11 = _lld_init_env;
          *(undefined4 *)(iVar5 + _lld_init_env) = 0;
          *(byte *)(iVar11 + 0x2b) = ~(byte)(1 << uVar4) & *(byte *)(iVar11 + 0x2b);
        }
        else if (*(char *)(iVar11 + 0x31) == '\x01') {
          bVar2 = *(byte *)(iVar11 + 0x52);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar5) = 1;
          _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
          *(undefined1 *)(iVar11 + 0x31) = 2;
        }
      }
      if (uVar4 != 0) break;
      uVar4 = 1;
    }
    if (*(char *)(_lld_init_env + 0x2b) == '\0') {
      if (*(int *)(_lld_init_env + 8) == 0) {
        puVar7 = (undefined1 *)r_ke_msg_alloc(0x209,0,0xff,0x38);
        uVar1 = *(undefined1 *)(_lld_init_env + 0x2c);
        puVar7[1] = 0;
        *puVar7 = uVar1;
      }
      r_ke_msg_send();
      r_ke_free(_lld_init_env);
      _lld_init_env = 0;
    }
    return;
  }
  r_sch_arb_remove(iVar11,1);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  iVar5 = uVar4 * 0x5a + 0x18;
  if ((*(ushort *)(iVar8 + iVar5) >> 10 & 1) != 0) {
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uVar6 = *(ushort *)(iVar8 + iVar5);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar8 + iVar5) = uVar6 & 0xfbff;
    *(undefined1 *)(iVar11 + 0x3d) = 0;
  }
  r_lld_init_process_pkt_rx(param_1);
  r_lld_init_process_pkt_tx(param_1);
  if ((_lld_init_env == 0) || (*(int *)(_lld_init_env + param_1 * 4) == 0)) {
    return;
  }
  iVar11 = *(int *)(_lld_init_env + param_1 * 4);
  iVar5 = r_lld_read_clock();
  bVar2 = *(byte *)(iVar11 + 0x52);
  uVar4 = (iVar5 - param_2 & 0xfffffffU) + 1 >> 1;
  if (*(char *)(iVar11 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar11 + 4) = *(undefined4 *)(iVar11 + 0x40);
    *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(iVar11 + 0x44);
    *(uint *)(iVar11 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar11 + 0x4d) * 2) +
         *(int *)(iVar11 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar10 = DAT_0001303e;
    if (DAT_0001303e < *(byte *)(iVar11 + 0x16)) {
      bVar10 = *(byte *)(iVar11 + 0x16);
    }
    *(byte *)(iVar11 + 0x16) = bVar10;
    *(ushort *)(iVar11 + 0x14) = DAT_0001303f & 0xf | 0x2000;
    iVar8 = r_sch_arb_insert(iVar11);
    if (iVar8 == 0) {
      uVar12 = (uint)*(byte *)(iVar11 + 0x4d);
      uVar4 = *(uint *)(iVar11 + 0x48);
      *(char *)(iVar11 + 0x3e) = (1 < uVar12) + '\x02';
      if ((uVar12 << 4 & 0xffffffcf) != 0) {
        r_assert_err(0x10000,0x1bf);
      }
      iVar8 = (uint)bVar2 * 0x5a;
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      uVar6 = *(ushort *)(iVar5 + iVar8 + 4);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar8 + 4) = uVar6 & 0xffcf | (ushort)(uVar12 << 4);
      uVar6 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar12 * 2);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + 0x20 + iVar5) = (ushort)(((uint)uVar6 + uVar4 + 0x270) / 0x271) & 0xff;
      if (uVar4 < 0x4000) {
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        uVar6 = (ushort)(uVar4 + 1 >> 1);
      }
      else {
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        uVar6 = (ushort)((uVar4 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      *(ushort *)(iVar5 + iVar8 + 0x1a) = uVar6;
      uVar4 = (uint)*(byte *)(iVar11 + 0x4c) << 10;
      if ((uVar4 & 0x30000) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      uVar6 = *(ushort *)(iVar5 + iVar8 + 0x26);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + iVar8 + 0x26) = uVar6 & 0x3ff | (ushort)uVar4;
      goto _L84;
    }
    *(undefined1 *)(iVar11 + 0x3d) = 0;
  }
  if (uVar4 < *(uint *)(iVar11 + 0x24)) {
    uVar4 = *(uint *)(iVar11 + 0x24) - uVar4;
  }
  else {
    r_sch_slice_bg_remove(1);
    uVar4 = (uint)*(ushort *)(iVar11 + 0x2e);
    uVar12 = _sch_slice_params;
    if (_sch_slice_params == 0xffffffff) {
      uVar12 = (*(ushort *)(iVar11 + 0x2c) - uVar4) * 2 + iVar5 & 0xffffffc;
    }
    *(uint *)(iVar11 + 4) = uVar12;
    *(undefined4 *)(iVar11 + 8) = 0;
  }
  uVar9 = (uint)_r_assert_param;
  *(uint *)(iVar11 + 0x24) = uVar4;
  uVar12 = uVar4 * 0x4e2;
  if (uVar9 < uVar4 * 0x4e2) {
    uVar12 = uVar9;
  }
  *(uint *)(iVar11 + 0x10) = uVar12;
  if (param_3 == 0) {
    *(undefined1 *)(iVar11 + 0x16) = DAT_00013042;
    *(undefined4 *)(iVar11 + 0x28) = *(undefined4 *)(iVar11 + 4);
  }
  iVar8 = (uint)bVar2 * 0x5a;
  *(ushort *)(iVar11 + 0x14) = DAT_00013043 & 0xf | 0x6000;
  *(undefined1 *)(iVar11 + 0x3e) = 1;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar8 + 0x20 + iVar5) = (short)uVar4;
  uVar4 = *(uint *)(iVar11 + 0x24);
  if ((uVar4 >> 0xf & 1) != 0) {
    r_assert_err(0,0x10000,0x4ab);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar8 + 0x1a + iVar5) = (ushort)uVar4 | 0x8000;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar8 + 0x46 + iVar5) = 0;
  iVar5 = r_sch_arb_insert(iVar11);
  if (iVar5 != 0) {
    r_assert_err(0,0x10000,0x280);
    return;
  }
_L84:
  *(undefined1 *)(iVar11 + 0x50) = 0;
  return;
}

