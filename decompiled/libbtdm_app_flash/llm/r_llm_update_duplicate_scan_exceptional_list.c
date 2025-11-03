/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_update_duplicate_scan_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_llm_update_duplicate_scan_exceptional_list(uint param_1,uint param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  size_t sVar6;
  undefined4 *puVar7;
  
  iVar1 = p_le_scan_duplicate_option;
  if (param_1 == 1) {
    if (param_3 == (void *)0x0) {
_L105:
      iVar2 = 0x12;
      goto _L67;
    }
    switch(param_2) {
    case 0:
      puVar7 = (undefined4 *)(p_le_scan_duplicate_option + 0x2c);
      sVar6 = 6;
      goto _L91;
    case 1:
      puVar7 = (undefined4 *)(p_le_scan_duplicate_option + 0x34);
      sVar6 = 4;
_L91:
      puVar3 = (undefined4 *)*puVar7;
      do {
        if (puVar3 == (undefined4 *)0x0) {
          uVar5 = 0;
_L99:
          if (*(int *)(iVar1 + 0x2c) == 0) {
            *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xfffffffe;
          }
          if (*(int *)(iVar1 + 0x34) == 0) {
            *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xfffffffd;
          }
          r_ble_log_internal_x2(0x40c100e2,param_2,sVar6 << 8 | uVar5);
          return 0;
        }
        iVar2 = memcmp(puVar3 + 1,param_3,sVar6);
        if (iVar2 == 0) {
          r_co_list_extract(puVar7,puVar3);
          r_ke_free(puVar3);
          uVar5 = 1;
          goto _L99;
        }
        puVar3 = (undefined4 *)*puVar3;
      } while( true );
    case 2:
      uVar5 = *(uint *)(p_le_scan_duplicate_option + 0x28) & 0xfffffffb;
      break;
    case 3:
      uVar5 = *(uint *)(p_le_scan_duplicate_option + 0x28) & 0xfffffff7;
      break;
    case 4:
      uVar5 = *(uint *)(p_le_scan_duplicate_option + 0x28) & 0xffffffef;
      break;
    case 5:
      uVar5 = *(uint *)(p_le_scan_duplicate_option + 0x28) & 0xffffffdf;
      break;
    case 6:
      uVar5 = *(uint *)(p_le_scan_duplicate_option + 0x28) & 0xffffffbf;
      break;
    default:
      goto _L105;
    }
    *(uint *)(p_le_scan_duplicate_option + 0x28) = uVar5;
    return 0;
  }
  if (param_1 == 2) {
    *(uint *)(p_le_scan_duplicate_option + 0x28) =
         *(uint *)(p_le_scan_duplicate_option + 0x28) & ~param_2;
    if ((param_2 & 1) != 0) {
      llm_util_flush_list(iVar1 + 0x2c);
    }
    if ((param_2 & 2) != 0) {
      llm_util_flush_list(iVar1 + 0x34);
    }
    r_ble_log_internal_x1(0x40c100e0,param_2);
    return 0;
  }
  iVar2 = 0xc;
  if (param_1 != 0) goto _L67;
  if (param_3 == (void *)0x0) goto _L105;
  switch(param_2) {
  case 0:
    piVar4 = (int *)(p_le_scan_duplicate_option + 0x2c);
    sVar6 = 6;
    goto _L76;
  case 1:
    piVar4 = (int *)(p_le_scan_duplicate_option + 0x34);
    sVar6 = 4;
_L76:
    for (piVar4 = (int *)*piVar4; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      iVar2 = memcmp(piVar4 + 1,param_3,sVar6);
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = r_ke_malloc(0xc,0);
    if (iVar2 != 0) {
      if (param_2 == 0) {
        memcpy((void *)(iVar2 + 4),param_3,6);
        r_co_list_push_front(iVar1 + 0x2c,iVar2);
        uVar5 = *(uint *)(iVar1 + 0x28) | 1;
      }
      else {
        memcpy((void *)(iVar2 + 4),param_3,4);
        r_co_list_push_front(iVar1 + 0x34,iVar2);
        uVar5 = *(uint *)(iVar1 + 0x28) | 2;
      }
      *(uint *)(iVar1 + 0x28) = uVar5;
      r_ble_log_internal_x2(0x40c100e1,param_2,sVar6 << 8);
      return 0;
    }
    iVar2 = 7;
_L67:
    r_ble_log_internal_x2(0x80c100e3,param_2,iVar2 << 8 | param_1);
    return iVar2;
  case 2:
    uVar5 = *(uint *)(p_le_scan_duplicate_option + 0x28) | 4;
    break;
  case 3:
    uVar5 = *(uint *)(p_le_scan_duplicate_option + 0x28) | 8;
    break;
  case 4:
    uVar5 = *(uint *)(p_le_scan_duplicate_option + 0x28) | 0x10;
    break;
  case 5:
    uVar5 = *(uint *)(p_le_scan_duplicate_option + 0x28) | 0x20;
    break;
  case 6:
    uVar5 = *(uint *)(p_le_scan_duplicate_option + 0x28) | 0x40;
    break;
  default:
    goto _L105;
  }
  *(uint *)(p_le_scan_duplicate_option + 0x28) = uVar5;
  return 0;
}

