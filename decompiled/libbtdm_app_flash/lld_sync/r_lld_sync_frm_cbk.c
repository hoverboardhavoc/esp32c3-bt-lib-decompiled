/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_cbk(uint param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  short sVar12;
  uint uVar13;
  char acStack_41 [16];
  char acStack_31 [9];
  
  iVar8 = r_sdk_config_get_opts();
  if (*(byte *)(iVar8 + 0xd) <= param_1) {
    r_assert_param(param_1,param_2,"lld_sync.c",0x458);
  }
  if (param_2 == 1) {
    cVar9 = '\x01';
  }
  else {
    if (param_2 != 0) {
      if (param_2 == 2) {
        param_1 = param_1 & 0xff;
        if (*(int *)(&lld_sync_env + param_1 * 4) == 0) {
          r_assert_err(0,"lld_sync.c",0x421);
          return;
        }
        iVar8 = *(int *)(&lld_sync_env + param_1 * 4);
        while (iVar5 = r_lld_rxdesc_check_hack(param_1), iVar5 != 0) {
          if (*(ushort *)(iVar8 + 0x52) < 0x673) {
            bVar3 = *(char *)(iVar8 + 99) == '\0';
            r_lld_sync_process_pkt_rx_aux_sync_ind(param_1,bVar3);
            r_lld_sync_process_pkt_rx_pkt_check(param_1,bVar3);
          }
          r_lld_rxdesc_free();
        }
        return;
      }
      if (param_2 != 4) {
        r_assert_param(param_1,param_2,"lld_sync.c",0x46e);
        return;
      }
      iVar8 = *(int *)(&lld_sync_env + (param_1 & 0xff) * 4);
      if (iVar8 == 0) {
        r_assert_err(0,"lld_sync.c",1099);
        return;
      }
      r_sch_arb_remove(iVar8,1);
      if (*(char *)(iVar8 + 99) == '\x01') {
        r_lld_sync_trunc_ind(param_1 & 0xff);
        *(undefined1 *)(iVar8 + 99) = 0;
      }
      param_1 = (uint)*(byte *)(iVar8 + 0x55);
      if (*(char *)(iVar8 + 0x5b) != '\x02') {
        acStack_41[0] = '\x01';
        goto r_lld_sync_sched;
      }
      goto code_r0x000103da;
    }
    cVar9 = '\0';
  }
  param_1 = param_1 & 0xff;
  iVar8 = *(int *)(&lld_sync_env + param_1 * 4);
  if (iVar8 == 0) {
    r_assert_err(0,"lld_sync.c",0x409);
    return;
  }
  bVar1 = *(byte *)(iVar8 + 0x55);
  r_sch_arb_remove(iVar8,1);
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  iVar5 = (uint)bVar1 * 0x5a + 0x18;
  if ((*(ushort *)(iVar7 + iVar5) >> 10 & 1) != 0) {
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar7 + iVar5);
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar7) = uVar2 & 0xfbff;
    if (*(char *)(iVar8 + 0x62) == '\x01') {
      r_lld_sync_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar8 + 99) = 0;
  }
  r_lld_sync_process_pkt_rx(param_1);
  if (((*(char *)(iVar8 + 99) == '\x02') ||
      ((*(char *)(iVar8 + 100) == '\0' && (*(char *)(iVar8 + 99) == '\x01')))) &&
     (*(char *)(iVar8 + 0x62) == '\x01')) {
    r_lld_sync_trunc_ind(param_1);
    *(undefined1 *)(iVar8 + 99) = 0;
  }
  acStack_41[0] = cVar9;
  if (*(char *)(iVar8 + 0x5b) != '\x02') {
r_lld_sync_sched:
    iVar8 = *(int *)(&lld_sync_env + param_1 * 4);
    acStack_31[0] = '\0';
    do {
      bVar1 = DAT_00012055;
      if (acStack_41[0] == '\0') {
        *(undefined1 *)(iVar8 + 0x16) = co_sca2ppm;
      }
      else {
        if (0xff < (uint)*(byte *)(iVar8 + 0x16) + (uint)DAT_00012055) {
          r_assert_err(0,"lld_sync.c",0x329);
        }
        *(byte *)(iVar8 + 0x16) = bVar1 + *(char *)(iVar8 + 0x16);
      }
      if (*(char *)(iVar8 + 99) == '\x01') {
        uVar10 = *(uint *)(iVar8 + 0x2c);
        bVar1 = *(byte *)(iVar8 + 0x31);
        iVar5 = (int)*(short *)(iVar8 + 0x28);
        uVar13 = *(uint *)(iVar8 + 0x24);
      }
      else {
        iVar5 = 1;
        if ((((*(char *)(iVar8 + 100) != '\0') && (*(char *)(iVar8 + 0x62) == '\0')) &&
            (*(short *)(iVar8 + 0x4c) != 0)) && (iVar5 = -1, acStack_41[0] == '\0')) {
          sVar12 = *(short *)(iVar8 + 0x4c) + 1;
          iVar5 = (int)sVar12;
          *(short *)(iVar8 + 0x4e) = sVar12 + *(short *)(iVar8 + 0x4a);
        }
        *(short *)(iVar8 + 0x4a) = *(short *)(iVar8 + 0x4a) + (short)iVar5;
        *(uint *)(iVar8 + 0x44) =
             iVar5 * *(int *)(iVar8 + 0x40) + *(int *)(iVar8 + 0x44) & 0xfffffff;
        iVar5 = r_lld_read_clock();
        if ((iVar5 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar8 + 0x44)) & 0xfffffff) < 0x8000001)
        {
          iVar5 = r_lld_read_clock();
          uVar10 = iVar5 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar8 + 0x44)) & 0xfffffff;
          if (uVar10 != 0) {
            uVar2 = *(ushort *)(iVar8 + 0x4a);
            uVar11 = *(uint *)(iVar8 + 0x40);
            if (((uint)uVar2 - (uint)*(ushort *)(iVar8 + 0x4e) & 0xffff) < 0x7fff) {
              iVar5 = ((uVar11 - 1) + uVar10) / uVar11 << 0x10;
            }
            else {
              iVar5 = ((*(ushort *)(iVar8 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
              *(undefined1 *)(iVar8 + 100) = 0;
            }
            *(ushort *)(iVar8 + 0x4a) = (short)((uint)iVar5 >> 0x10) + uVar2;
            *(uint *)(iVar8 + 0x44) = (iVar5 >> 0x10) * uVar11 + *(int *)(iVar8 + 0x44) & 0xfffffff;
          }
        }
        else {
          r_lld_read_clock();
        }
        if (*(char *)(iVar8 + 0x57) == '\0') {
          uVar10 = *(int *)(iVar8 + 0x40) * 6;
        }
        else {
          uVar10 = *(uint *)(iVar8 + 0x34);
        }
        if (uVar10 < (*(int *)(iVar8 + 0x44) - *(int *)(iVar8 + 0x3c) & 0xfffffffU)) {
_L211:
          r_lld_sync_cleanup(param_1,8);
          return;
        }
        iVar5 = r_rwip_active_check();
        uVar10 = 0x14;
        if (iVar5 == 0) {
          uVar10 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        iVar5 = (((uint)((*(int *)(iVar8 + 0x44) - *(int *)(iVar8 + 0x38)) * 0x10) >> 8) *
                (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar8 + 0x5a) * 2) + uVar10)) / 100 +
                0x10;
        uVar10 = iVar5 * 2;
        uVar13 = *(int *)(iVar8 + 0x44) - uVar10 / 0x271 & 0xfffffff;
        uVar11 = (uint)*(ushort *)(iVar8 + 0x48) + iVar5 * -2 + (uVar10 / 0x271) * 0x271;
        iVar5 = (int)(short)uVar11;
        if (iVar5 < 0) {
          uVar13 = uVar13 - 1 & 0xfffffff;
          iVar5 = (int)(((uVar11 & 0xffff) + 0x271) * 0x10000) >> 0x10;
        }
        if (*(char *)(iVar8 + 0x57) == '\0') {
          iVar7 = 300;
          if (*(char *)(iVar8 + 0x56) == '\0') {
            iVar7 = 0x1e;
          }
          uVar10 = uVar10 + iVar7;
          if (((uint)(*(int *)(iVar8 + 0x40) * 0x271) >> 1) - 0x96 < uVar10 >> 1) goto _L211;
        }
        *(undefined2 *)(iVar8 + 0x52) = 0;
        bVar1 = *(byte *)(iVar8 + 0x58);
      }
      uVar11 = (uint)_DAT_00012066;
      *(uint *)(iVar8 + 4) = uVar13;
      uVar2 = *(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2);
      *(int *)(iVar8 + 8) = iVar5;
      uVar10 = uVar10 * 2 + uVar11 + (uint)uVar2 * 2;
      if (uVar10 < 0x61a81) {
        *(uint *)(iVar8 + 0x10) = uVar10;
      }
      else {
        *(undefined4 *)(iVar8 + 0x10) = 400000;
      }
      r_lld_sync_insert_eco(param_1,acStack_41,acStack_31);
      if (acStack_31[0] != '\0') {
        return;
      }
    } while( true );
  }
code_r0x000103da:
  piVar4 = (int *)(&lld_sync_env + param_1 * 4);
  if (*piVar4 != 0) {
    puVar6 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
    *puVar6 = (char)param_1;
    puVar6[1] = 0;
    r_ke_msg_send();
    r_ke_free(*piVar4);
    *piVar4 = 0;
  }
  return;
}

