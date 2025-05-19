/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_update_duplicate_scan_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llm_update_duplicate_scan_exceptional_list(int param_1,uint param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  size_t sVar8;
  
  iVar1 = p_le_scan_duplicate_option;
  if (param_1 != 1) {
    if (param_1 == 2) {
      *(uint *)(p_le_scan_duplicate_option + 0x28) =
           *(uint *)(p_le_scan_duplicate_option + 0x28) & ~param_2;
      if ((param_2 & 1) != 0) {
        llm_util_flush_list(iVar1 + 0x2c);
      }
      if ((param_2 & 2) != 0) {
        llm_util_flush_list(iVar1 + 0x34);
      }
      goto _L116;
    }
    if (param_1 != 0) {
      return 0xc;
    }
    if (param_3 == (void *)0x0) {
_L111:
      return 0x12;
    }
    switch(param_2) {
    case 0:
      piVar5 = (int *)(p_le_scan_duplicate_option + 0x2c);
      sVar8 = 6;
      goto _L76;
    case 1:
      piVar5 = (int *)(p_le_scan_duplicate_option + 0x34);
      sVar8 = 4;
_L76:
      for (piVar5 = (int *)*piVar5; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
        iVar4 = memcmp(piVar5 + 1,param_3,sVar8);
        if (iVar4 == 0) goto _L116;
      }
      iVar4 = r_ke_malloc(0xc,0);
      if (iVar4 == 0) {
        return 7;
      }
      if (param_2 == 0) {
        memcpy((void *)(iVar4 + 4),param_3,6);
        r_co_list_push_front(iVar1 + 0x2c,iVar4);
        uVar6 = *(uint *)(iVar1 + 0x28) | 1;
      }
      else {
        memcpy((void *)(iVar4 + 4),param_3,4);
        r_co_list_push_front(iVar1 + 0x34,iVar4);
        uVar6 = *(uint *)(iVar1 + 0x28) | 2;
      }
      break;
    case 2:
      uVar6 = *(uint *)(p_le_scan_duplicate_option + 0x28) | 4;
      break;
    case 3:
      uVar6 = *(uint *)(p_le_scan_duplicate_option + 0x28) | 8;
      break;
    case 4:
      uVar6 = *(uint *)(p_le_scan_duplicate_option + 0x28) | 0x10;
      break;
    case 5:
      uVar6 = *(uint *)(p_le_scan_duplicate_option + 0x28) | 0x20;
      break;
    case 6:
      uVar6 = *(uint *)(p_le_scan_duplicate_option + 0x28) | 0x40;
      break;
    default:
      goto _L111;
    }
    *(uint *)(iVar1 + 0x28) = uVar6;
    return 0;
  }
  uVar2 = 0x12;
  if (param_3 == (void *)0x0) {
    return 0x12;
  }
  switch(param_2) {
  case 0:
    puVar7 = (undefined4 *)(p_le_scan_duplicate_option + 0x2c);
    sVar8 = 6;
    goto _L90;
  case 1:
    puVar7 = (undefined4 *)(p_le_scan_duplicate_option + 0x34);
    sVar8 = 4;
_L90:
    for (puVar3 = (undefined4 *)*puVar7; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3
        ) {
      iVar4 = memcmp(puVar3 + 1,param_3,sVar8);
      if (iVar4 == 0) {
        r_co_list_extract(puVar7,puVar3);
        r_ke_free(puVar3);
        break;
      }
    }
    if (*(int *)(iVar1 + 0x2c) == 0) {
      *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xfffffffe;
    }
    if (*(int *)(iVar1 + 0x34) == 0) {
      uVar6 = *(uint *)(iVar1 + 0x28) & 0xfffffffd;
      break;
    }
    goto _L116;
  case 2:
    uVar6 = *(uint *)(p_le_scan_duplicate_option + 0x28) & 0xfffffffb;
    break;
  case 3:
    uVar6 = *(uint *)(p_le_scan_duplicate_option + 0x28) & 0xfffffff7;
    break;
  case 4:
    uVar6 = *(uint *)(p_le_scan_duplicate_option + 0x28) & 0xffffffef;
    break;
  case 5:
    uVar6 = *(uint *)(p_le_scan_duplicate_option + 0x28) & 0xffffffdf;
    break;
  case 6:
    uVar6 = *(uint *)(p_le_scan_duplicate_option + 0x28) & 0xffffffbf;
    break;
  default:
    goto _L111;
  }
  *(uint *)(iVar1 + 0x28) = uVar6;
_L116:
  uVar2 = 0;
_L111:
  return uVar2;
}

