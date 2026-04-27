/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_skip_isr(uint param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 == 0) {
    uVar6 = 0xbe6;
_L1053:
    r_assert_err(0,0x10000,uVar6);
    return;
  }
  r_ble_log_internal_x2(0x404000ed,(uint)*(byte *)(iVar2 + 0x89) << 8 | param_1);
  if (1 < (byte)(*(char *)(iVar2 + 0x89) - 1U)) {
    r_assert_err(0,0x10000,0xb9b);
  }
  if (*(char *)(iVar2 + 0x89) == '\x02') {
    uVar5 = 0;
  }
  else {
    if ((*(char *)(iVar2 + 0x95) == '\0') || (*(int *)(iVar2 + 0x38) != param_2)) {
      r_sch_arb_remove(iVar2,1);
      if ((*(ushort *)(iVar2 + 0x74) & 8) == 0) {
        if ((uint)(*(int *)(iVar2 + 100) << 1) <= (param_2 - *(int *)(iVar2 + 0x5c) & 0xfffffffU)) {
          *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + rwip_priority;
          *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(iVar2 + 4);
        }
      }
      else {
        *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + rwip_priority;
      }
      iVar4 = r_sch_arb_insert(iVar2);
      if (iVar4 == 0) goto _L1046;
      if (*(char *)(iVar2 + 0x95) != '\0') {
        return;
      }
      if (*(int *)(iVar2 + 0x58) == -1) {
        uVar6 = 0xbda;
        goto _L1053;
      }
    }
    else {
      r_sch_arb_remove(iVar2 + 0x34,1);
      cVar1 = rwip_priority;
      if ((uint)(*(int *)(iVar2 + 100) << 1) <= (param_2 - *(int *)(iVar2 + 0x60) & 0xfffffffU)) {
        *(int *)(iVar2 + 0x60) = param_2;
        *(char *)(iVar2 + 0x4a) = *(char *)(iVar2 + 0x4a) + cVar1;
      }
      iVar4 = r_sch_arb_insert(iVar2 + 0x34);
      if (iVar4 == 0) {
_L1046:
        *(undefined1 *)(iVar2 + 0x89) = 0;
        return;
      }
      if (*(int *)(iVar2 + 0x58) == -1) {
        uVar6 = 3000;
        goto _L1053;
      }
    }
    param_1 = (uint)*(byte *)(iVar2 + 0x87);
    uVar5 = 0x3c;
  }
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 != 0) {
    r_ble_log_internal_x1
              (0x400000da,(uint)*(byte *)(iVar2 + 0x89) << 0x18 | uVar5 << 0x10 | 0x100 | param_1);
    if ((((*(short *)(iVar2 + 0x24) != 0) && (*(short *)(iVar2 + 0x7e) != 0)) &&
        (*(short *)(iVar2 + 0x24) != *(short *)(iVar2 + 0x7e))) &&
       (((*(ushort *)(iVar2 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10))))
    {
      iVar4 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar4 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar2 + 0x7e));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr();
      }
    }
    if (((*(short *)(iVar2 + 0x26) != 0) && (*(short *)(iVar2 + 0x80) != 0)) &&
       ((*(short *)(iVar2 + 0x26) != *(short *)(iVar2 + 0x80) &&
        (((*(ushort *)(iVar2 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10))))
       )) {
      iVar4 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar4 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar2 + 0x80));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr();
      }
    }
  }
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 != 0) {
    r_sch_arb_remove(iVar2,0);
    if (*(char *)(iVar2 + 0x95) != '\0') {
      r_sch_arb_remove(iVar2 + 0x34,0);
    }
    if ((*(ushort *)(iVar2 + 0x74) & 8) != 0) {
      r_sch_slice_fg_remove(2);
    }
    puVar3 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
    *puVar3 = (char)param_1;
    puVar3[1] = (char)uVar5;
    puVar3[0x35] = 0;
    if ((uVar5 != 0) && (uVar5 = 0, *(short *)(iVar2 + 0x78) != 0)) {
      uVar5 = (uint)*(byte *)(iVar2 + 0x86);
    }
    puVar3[0x38] = (char)uVar5;
    r_ke_msg_send();
    r_ke_free(*(undefined4 *)(&lld_adv_env + param_1 * 4));
    *(undefined4 *)(&lld_adv_env + param_1 * 4) = 0;
  }
  return;
}

