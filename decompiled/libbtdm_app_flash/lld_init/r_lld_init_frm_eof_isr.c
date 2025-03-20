/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  char cVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  g_initor_evt_end_abort = (undefined1)param_3;
  if (_lld_init_env == 0) {
_L215:
    r_assert_param(_lld_init_env,"lld_init.c",0x4c0);
    return;
  }
  iVar12 = *(int *)(_lld_init_env + param_1 * 4);
  if (iVar12 == 0) goto _L215;
  cVar2 = *(char *)(iVar12 + 0x31);
  *(undefined1 *)(iVar12 + 0x31) = 0;
  bVar3 = *(byte *)(iVar12 + 0x52);
  if (cVar2 == '\x02') {
    while (iVar12 = r_lld_rxdesc_check_hack((uint)bVar3), iVar12 != 0) {
      r_lld_rxdesc_free();
    }
    iVar12 = 0;
    while( true ) {
      iVar5 = iVar12 * 4;
      iVar8 = *(int *)(_lld_init_env + iVar5);
      if (iVar8 != 0) {
        if (*(char *)(iVar8 + 0x31) == '\0') {
          r_sch_arb_remove(iVar8,0);
          r_sch_slice_bg_remove(1);
          r_ke_free(*(undefined4 *)(_lld_init_env + iVar5));
          iVar8 = _lld_init_env;
          *(undefined4 *)(iVar5 + _lld_init_env) = 0;
          *(byte *)(iVar8 + 0x2b) = ~(byte)(1 << iVar12) & *(byte *)(iVar8 + 0x2b);
        }
        else if (*(char *)(iVar8 + 0x31) == '\x01') {
          bVar3 = *(byte *)(iVar8 + 0x52);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar5 + (uint)bVar3 * 0x5a + 0x20) = 1;
          _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
          *(undefined1 *)(iVar8 + 0x31) = 2;
        }
      }
      if (iVar12 != 0) break;
      iVar12 = 1;
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
  r_sch_arb_remove(iVar12,1);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  iVar5 = (uint)bVar3 * 0x5a + 0x18;
  if ((*(ushort *)(iVar8 + iVar5) >> 10 & 1) != 0) {
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(ushort *)(iVar8 + iVar5);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar8) = uVar4 & 0xfbff;
    *(undefined1 *)(iVar12 + 0x3d) = 0;
  }
  r_lld_init_process_pkt_rx(param_1);
  r_lld_init_process_pkt_tx(param_1);
  if ((_lld_init_env == 0) || (*(int *)(param_1 * 4 + _lld_init_env) == 0)) {
    return;
  }
  iVar12 = *(int *)(_lld_init_env + param_1 * 4);
  iVar5 = r_lld_read_clock();
  uVar10 = (iVar5 - param_2 & 0xfffffffU) + 1 >> 1;
  bVar3 = *(byte *)(iVar12 + 0x52);
  if (*(char *)(iVar12 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar12 + 4) = *(undefined4 *)(iVar12 + 0x40);
    *(undefined4 *)(iVar12 + 8) = *(undefined4 *)(iVar12 + 0x44);
    *(uint *)(iVar12 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar12 + 0x4d) * 2) +
         *(int *)(iVar12 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar9 = DAT_00013036;
    if (DAT_00013036 < *(byte *)(iVar12 + 0x16)) {
      bVar9 = *(byte *)(iVar12 + 0x16);
    }
    *(byte *)(iVar12 + 0x16) = bVar9;
    *(ushort *)(iVar12 + 0x14) = DAT_00013037 & 0xf | 0x2000;
    iVar8 = r_sch_arb_insert(iVar12);
    if (iVar8 == 0) {
      uVar11 = (uint)*(byte *)(iVar12 + 0x4d);
      uVar10 = *(uint *)(iVar12 + 0x48);
      *(char *)(iVar12 + 0x3e) = (1 < uVar11) + '\x02';
      if ((uVar11 << 4 & 0xffffffcf) != 0) {
        r_assert_err("lld_init.c",0x1bf);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar5 = (uint)bVar3 * 0x5a;
      uVar4 = *(ushort *)(iVar8 + iVar5 + 4);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar5 + 4) = uVar4 & 0xffcf | (ushort)(uVar11 << 4);
      uVar4 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar11 * 2);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar8 + iVar5 + 0x20) = (ushort)(((uint)uVar4 + uVar10 + 0x270) / 0x271) & 0xff;
      if (uVar10 < 0x4000) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)(iVar8 + iVar5 + 0x1a) = (short)(uVar10 + 1 >> 1);
      }
      else {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar8 + iVar5 + 0x1a) = (ushort)((uVar10 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar10 = (uint)*(byte *)(iVar12 + 0x4c) << 10;
      if ((uVar10 & 0x30000) != 0) {
        r_assert_err(0,"lld_init.c",0x635);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar8 + iVar5 + 0x26);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + 0x26 + iVar8) = uVar4 & 0x3ff | (ushort)uVar10;
      goto _L81;
    }
    *(undefined1 *)(iVar12 + 0x3d) = 0;
  }
  if (uVar10 < *(uint *)(iVar12 + 0x24)) {
    *(uint *)(iVar12 + 0x24) = *(uint *)(iVar12 + 0x24) - uVar10;
  }
  else {
    r_sch_slice_bg_remove(1);
    if (_sch_slice_params == -1) {
      *(uint *)(iVar12 + 4) =
           ((uint)*(ushort *)(iVar12 + 0x2c) - (uint)*(ushort *)(iVar12 + 0x2e)) * 2 + iVar5 &
           0xffffffc;
    }
    else {
      *(int *)(iVar12 + 4) = _sch_slice_params;
    }
    *(undefined4 *)(iVar12 + 8) = 0;
    *(uint *)(iVar12 + 0x24) = (uint)*(ushort *)(iVar12 + 0x2e);
  }
  iVar5 = *(int *)(iVar12 + 0x24);
  uVar10 = iVar5 * 0x4e2;
  if (_r_assert_param < uVar10) {
    uVar10 = (uint)_r_assert_param;
  }
  *(uint *)(iVar12 + 0x10) = uVar10;
  if (param_3 == 0) {
    *(undefined1 *)(iVar12 + 0x16) = DAT_0001303a;
    *(undefined4 *)(iVar12 + 0x28) = *(undefined4 *)(iVar12 + 4);
  }
  *(ushort *)(iVar12 + 0x14) = DAT_0001303b & 0xf | 0x6000;
  *(undefined1 *)(iVar12 + 0x3e) = 1;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  iVar8 = (uint)bVar3 * 0x5a;
  *(short *)(iVar7 + iVar8 + 0x20) = (short)iVar5;
  iVar5 = *(int *)(iVar12 + 0x24);
  if (iVar5 << 0x10 < 0) {
    r_assert_err(0,"lld_init.c",0x4ab);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar7 + iVar8 + 0x1a) = (ushort)iVar5 | 0x8000;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar8 + 0x46 + iVar5) = 0;
  iVar5 = r_sch_arb_insert(iVar12);
  if (iVar5 != 0) {
    r_assert_err(0,"lld_init.c",0x278);
    return;
  }
_L81:
  *(undefined1 *)(iVar12 + 0x50) = 0;
  return;
}

